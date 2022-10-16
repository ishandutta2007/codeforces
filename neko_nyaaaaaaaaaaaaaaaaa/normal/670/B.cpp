#include <bits/stdc++.h>
using namespace std;

int main() {
      int n, k;
      cin >> n >> k;
      vector<string> s(n);
      for (int i = 0; i < n; i++) {
            cin >> s[i];
      }
      int count = 1;
      while (k > count) {
            k -= count;
            count++;
      }
      cout << s[k-1];
      
      return 0;
}