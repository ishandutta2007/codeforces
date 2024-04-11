#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, m; cin >> n >> m;
      vector<ll> a(n);
      ll s = 0;
      for (int i = 0; i < n; i++) {cin >> a[i]; s += a[i];}
      sort(a.begin(), a.end());

      ll ans = 0;
      ll height = 0;
      for (int i = 0; i < n; i++) {
            if (a[i] > height) height++;
      }

      ll extra = a.back() - height;
      ans += s - n - extra;
      cout << ans;

      return 0;
}