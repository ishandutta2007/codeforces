#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 1e9+7;

vector<ll> ft(400007);

ll modpow(ll n, ll k) {
      if (k == 0) return 1;
      if (k == 1) return n;

      ll tmp = modpow(n, k/2);
      tmp = (tmp*tmp) % M;

      if (k & 1) tmp = (tmp*n) % M;
      return tmp;
}

void init() {
      ft[0] = ft[1] = 1;
      for (int i = 2; i <= 400002; i++) {
            ft[i] = (ft[i-1]*i) % M;
      }
}

ll nCr(ll n, ll r) {
      ll p = ft[n];
      ll q = (ft[r] * ft[n - r]) % M;

      return (p*modpow(q, M-2)) % M;
}

ll path_cnt(int a, int b, int x, int y) {
      ll row = x - a, col = y - b;
      return nCr(row + col, col);
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      init();

      ll n, m, k;
      cin >> n >> m >> k;
      vector<pair<ll, ll>> a(k+1);

      for (int i = 0; i < k; i++) {
            cin >> a[i].first >> a[i].second;
      }
      a[k].first = n; a[k].second = m;
      sort(a.begin(), a.end());

      vector<ll> dp(k+1);
      for (int i = 0; i <= k; i++) {
            ll x = a[i].first, y = a[i].second;
            dp[i] = path_cnt(1, 1, x, y);

            for (int j = 0; j < i; j++) {
                  ll p = a[j].first, q = a[j].second;
                  if (p <= x && q <= y) {
                        dp[i] -= dp[j]*path_cnt(p, q, x, y);
                        dp[i] %= M;
                        if (dp[i] < 0) dp[i] += M;
                  }
            }
      }
      cout << dp[k];

      return 0;
}