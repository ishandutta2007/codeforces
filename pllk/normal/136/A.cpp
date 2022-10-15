#include <iostream>

using namespace std;

int n;
int a[100+1];

int main() {
   cin >> n;
   for (int i = 1; i <= n; i++) {
       int k;
       cin >> k;
       a[k] = i;
   }
   for (int i = 1; i <= n; i++) {
       cout << a[i] << " ";
   }
   cout << endl;
}