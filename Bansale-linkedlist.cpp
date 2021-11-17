#include<iostream>

using namespace std;

class Node {
  public:
   int key;
   int data;
   Node * next;

   Node() {
      key = 0;
      data = 0;
      next = NULL;
   }
   Node(int k, int d) {
      key = k;
      data = d;
   }
};

class LinkedList {
  public:
   Node * head;

   LinkedList() {
      head = NULL;
   }
   LinkedList(Node * n) {
      head = n;
   }

  // Check 
   Node * nodeExists(int k) {
      Node * temp = NULL;
   
      Node * ptr = head;
      while (ptr != NULL) {
         if (ptr -> key == k) {
            temp = ptr;
         }
         ptr = ptr -> next;
      
      }
      return temp;
   }

  // 1. Insert node
   void InsertNode(Node * n) {
      if (nodeExists(n -> key) != NULL) {
         cout << "\nNode Already exists with key value : " << n -> key << ".\nInsert another node with different Key value" << endl;
      } 
      else {
         if (head == NULL) {
            head = n;
            cout << "Node Inserted" << endl;
         } 
         else {
            Node * ptr = head;
            while (ptr -> next != NULL) {
               ptr = ptr -> next;
            }
            ptr -> next = n;
            cout << "Node Inserted" << endl;
         }
      }
   
   }
   
  // 2. Delete node
   void DeleteNode(int k) {
      if (head == NULL) {
         cout << "\nLinked List already Empty. Cant delete" << endl;
      } 
      else if (head != NULL) {
         if (head -> key == k) {
            head = head -> next;
            cout << "\nNode Deleted with key value : " << k << endl;
         } 
         else {
            Node * temp = NULL;
            Node * prevptr = head;
            Node * currentptr = head -> next;
            while (currentptr != NULL) {
               if (currentptr -> key == k) {
                  temp = currentptr;
                  currentptr = NULL;
               } 
               else {
                  prevptr = prevptr -> next;
                  currentptr = currentptr -> next;
               }
            }
            if (temp != NULL) {
               prevptr -> next = temp -> next;
               cout << "\nNode Deleted with key value : " << k << endl;
            } 
            else {
               cout << "\nNode Doesn't exist with key value : " << k << endl;
            }
         }
      }
   
   }

  // Printing
   void printList() {
      if (head == NULL) {
         cout << "\nNo Nodes in Linked List";
      } 
      else {
         cout << endl << "\nLinked List Values : ";
         Node * temp = head;
      
         while (temp != NULL) {
            cout << "(" << temp -> key << "," << temp -> data << ") --> ";
            temp = temp -> next;
         }
      }
   
   }

};

int main() {

   LinkedList s;
   int option;
   int key1, k1, data1;
   cout <<"Linked list program\n";
   do {
      cout << "\nWhat operation do you wish to perform? Select Option number. Enter 0 to exit." << endl;
      cout << "1. InsertNode()" << endl;
      cout << "2. DeleteNode()" << endl;
      cout << "3. print()" << endl;
      cout << "4. Clear Screen" << endl << endl;
   
      cin >> option;
      Node * n1 = new Node();
   
      switch (option) {
          
         //InsertNode
         case 1:
            cout << "Insert Node Operation \nEnter key & data of the Node to be Inserted" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            
            s.InsertNode(n1);
            break;
            
         //DeleteNode
         case 2:
         
            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.DeleteNode(k1);
         
            break;
         
         //Display
         case 3:
            s.printList();
            cout << "\n\n";
         
            break;
            
         //Clearscreen
         case 4:
            system("cls");
            break;
         default:
            cout << "\nEnter Proper Option number " << endl;
      }
   
   } while (option != 0);

   return 0;
}