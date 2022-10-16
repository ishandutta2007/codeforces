#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

ll mpow(ll b, ll e) {
    if (e == 0) return 1;
    if (e % 2) return (b * mpow(b, e - 1)) % mod;
    ll tmp = mpow(b, e / 2);
    return (tmp * tmp) % mod;
}

int main() {
      ios::sync_with_stdio(0);
      
      ll n, k;
      cin >> n >> k;
      
      ll rs[k + 1];
      ll c[k + 1];
      
      ll prod = mpow(2, n);
      rs[0] = mpow(2, n);
      
      fill(c, c + k + 1, 0); c[0] = 1;
      for (ll i = 1; i <= k; ++i) {
            prod = (prod * (n - i + 1)) % mod;
            prod = (prod * 500000004) % mod;
      
            ll cnew[k + 1];
            cnew[0] = c[0];
            for (ll j = k; j > 0; --j) {
                  cnew[j] = c[j - 1];
            }
      
            cnew[0] = 0;
            for (ll j = k; j >= 0; --j) {
                  cnew[j] = (cnew[j] + c[j] - (i * c[j]) % mod) % mod;
                  if (cnew[j] < 0) cnew[j] += mod;
            }
      
            for (ll j = 0; j <= k; ++j) c[j] = cnew[j];
      
            rs[i] = prod;
            for (ll j = i - 1; j >= 0; --j) {
                  rs[i] = (rs[i] - (rs[j] * c[j]) % mod) % mod;
                  if (rs[i] < 0) rs[i] += mod;
            }
      }
      cout << (rs[k] % mod) << endl;
      
      return 0;
}