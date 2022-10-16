#include <bits/stdc++.h>
using namespace std;

int main() {
      string s1, s2, ans;
      cin >> s1 >> s2;
      ans += s1[0];
      int i = 1;
      while (i < s1.size()) {
            if (s1[i] < s2[0]) {ans += s1[i]; i++;}
            else break;
      }
      ans += s2[0];
      cout << ans;
}