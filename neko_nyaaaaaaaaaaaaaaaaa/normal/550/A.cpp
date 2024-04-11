#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      string s;
      cin >> s;
      int n = s.size();
      bool ba = 0, ab = 0;
      for (int i = 1; i < n; i++) {
            if (ba == 0) {
                  if (s[i] == 'A' && s[i-1] == 'B') {ba = 1; i++;}
            } else {
                  if (s[i] == 'B' && s[i-1] == 'A') {cout << "YES"; return 0;}
            }
      }
      for (int i = 1; i < n; i++) {
            if (ab == 0) {
                  if (s[i] == 'B' && s[i-1] == 'A') {ab = 1; i++;}
            } else {
                  if (s[i] == 'A' && s[i-1] == 'B') {cout << "YES"; return 0;}
            }
      }
      cout << "NO";
      
}