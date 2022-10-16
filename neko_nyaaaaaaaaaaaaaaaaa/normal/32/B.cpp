#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      string s;
      cin >> s;
      for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {cout << 0;}
            else {
                  i++;
                  if (s[i] == '.') {cout << 1;}
                  else {cout << 2;}
            }
      }
      
      return 0;
}