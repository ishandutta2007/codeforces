#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());
      for (int i = 2; i < n; i++) {
            if (a[i] < a[i-1] + a[i-2]) {cout << "YES"; return 0;}
      }
      cout << "NO";;
}