#include <bits/stdc++.h>
using namespace std;

int main() {
      string s;
      cin >> s;
      int op = 0;
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {op++; continue;}
            if (s[i] == ')') {
                  if (op) {
                        ans += 2; op--;
                  }
            }
      }
      cout << ans;
      return 0;
}