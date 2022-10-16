#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 998244353;

ll modpow(ll n, ll k) {
      if (k == 1) return n % M;

      ll tmp = modpow(n, k/2);
      tmp = (tmp*tmp) % M;
      if (k % 2) tmp = (tmp*n) % M;

      return tmp;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      string a, b; cin >> a >> b;

      ll pw = 1, ans = 0;
      ll cnt = 0;
      for (int i = 0; i < m; i++) {
            cnt += (b[i] == '1');
      }

      while (a.size() && b.size()) {
            char c = a.back(), d = b.back();
            a.pop_back(); b.pop_back();

            if (c == '1') {
                  ans = (ans + cnt*pw) % M;
            }

            pw = (pw*2) % M;
            cnt -= (d == '1');
      }
      cout << ans;

      return 0;
}