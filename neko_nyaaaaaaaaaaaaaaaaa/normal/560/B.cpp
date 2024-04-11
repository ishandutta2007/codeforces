#include <bits/stdc++.h>
using namespace std;


int a1, b1, a2, b2, a3, b3;

void yes() {
      cout << "YES"; exit(0);
}

void check() {
      if (a2 + a3 <= a1 && max(b2, b3) <= b1) yes();
      if (max(a2, a3) <= a1 && b2 + b3 <= b1) yes();
}

int main() {
      cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
      
      check();
      swap(a2, b2);
      check();
      swap(a3, b3);
      check();
      swap(a2, b2);
      check();
      
      cout << "NO";
      
      return 0;
}