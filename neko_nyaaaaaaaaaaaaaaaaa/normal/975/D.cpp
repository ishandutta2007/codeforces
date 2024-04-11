#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      int n, a, b;
      cin >> n >> a >> b;
      
      map<ll, ll> v;
      map<pair<ll, ll>, ll> s;
      
      ll ans = 0;
      while (n--) {
            ll xx, x, y;
            cin >> xx >> x >> y;
            ans += v[a*x - y] - s[{x, y}];
            v[a*x - y]++;
            s[{x, y}]++;
      }
      
      cout << ans*2;
}