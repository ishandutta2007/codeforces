#include <bits/stdc++.h>
using namespace std;

int main() {
      ios::sync_with_stdio(0);
      string s;
      cin >> s;
      stack<char> a;
      for (int i = 0; i < s.size(); i++) {
            if (a.empty()) {a.push(s[i]); continue;}
            if (a.top() == s[i]) {a.pop(); continue;}
            if (a.top() != s[i]) {a.push(s[i]); continue;}
      }
      if (a.empty()) {cout << "Yes"; return 0;}
      else {cout << "No"; return 0;}
}