#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      int odd = 0;
      cin >> n;
      vector<int> a(n);
      for (int i = 0 ; i <n ;i++) {
            cin >> a[i];
      }
      for (int i = 0; i < n; i++) {
            if (a[i] % 2) {cout << "First"; return 0;}
      }
      cout << "Second";
      return 0;
}