#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a(200005, 0);
vector<ll> b(200005, 0);

int main() {
      ios::sync_with_stdio(0);
      
      ll n, q, x, y, m;
      cin >> n >> q;
      m = n;
      while (n--) {
            cin >> a[n];
      }
      sort(a.begin(), a.end(), greater<ll>());
      while (q--) {
            cin >> x >> y;
            b[x-1]++;
            b[y]--;
      }
      for (int i = 1; i < 200005; i++) {
            b[i] += b[i-1];
      }
      sort(b.begin(), b.end(), greater<ll>());
      ll ans = 0;
      for (int i = 0; i < m; i++) {
            ans += a[i]*b[i];
      }
      cout << ans;
      
}