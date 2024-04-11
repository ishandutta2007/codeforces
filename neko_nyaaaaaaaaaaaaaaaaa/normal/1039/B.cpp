#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int query(ll l, ll r) {
      cout << l << " " << r << endl;
      string s; cin >> s;
      if (s == "Bad") exit(0);
      if (s == "No") return 0;
      if (l == r) exit(0);
      return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
      mt19937_64 random(time(0));

      ll n, k; cin >> n >> k;
      ll lo = 1, hi = n;
      while (1) {
            if (hi - lo <= 50) {
                  ll d = hi - lo + 1;
                  ll k = random() % d;
                  query(lo+k, lo+k);
                  hi = min(hi + k, n);
                  lo = max(lo - k, 1LL);
                  continue;
            }

            ll mid = (lo + hi)/2;
            int s = query(lo, mid);
            if (s) {
                  hi = mid;
            } else {
                  lo = mid + 1;
            }

            hi = min(hi + k, n);
            lo = max(lo - k, 1LL);
      }

	return 0;
}