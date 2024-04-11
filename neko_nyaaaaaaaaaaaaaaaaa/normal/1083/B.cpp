#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
string s, t;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int ans = 0;
      cin >> n >> k >> s >> t;
      if (s == t || k == 1) {cout << n; return 0;}
      k -= 2;

      reverse(s.begin(), s.end());
      reverse(t.begin(), t.end());

      while (s.size() && t.back() == s.back()) {
            ans++; n--;
            t.pop_back(); s.pop_back();
      }

      reverse(s.begin(), s.end());
      reverse(t.begin(), t.end());

      int left = 1, right = 1;
      for (int i = 0; i+1 < n; i++) {
            //cout << i << ' ' << left << ' ' << right << endl;

            ans += left+right;

            // left tree
            int l = left*2;
            if (s[i+1] == 'b') l--;       // l is the new node
            int need = l - left;
            need = min(need, k);
            k -= need; left += need;

            // right tree
            int r = right*2;
            if (t[i+1] == 'a') r--;
            need = r - right;
            need = min(need, k);
            k -= need; right += need;
      }

      //cout << n-1 << ' ' << left << ' ' << right << endl;

      ans += left+right;
      cout << ans;

      return 0;
}