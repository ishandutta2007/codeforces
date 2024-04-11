#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);

      int n;
      string s;
      cin >> n >> s;

      map<string, int> a;
      for (int i = 1; i < n; i++) {
            string tmp;
            tmp += s[i-1];
            tmp += s[i];
            a[tmp]++;
      }

      string ans = "ABCDE";
      for (auto it = a.begin(); it != a.end(); it++) {
            if (it->second > a[ans]) {
                  ans = it->first;
            }
      }
      cout << ans;

      return 0;
}