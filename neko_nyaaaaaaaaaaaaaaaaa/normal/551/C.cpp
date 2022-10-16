#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(vector<ll> a) {
      while (a.size() && a[a.size() - 1] == 0) {
            a.pop_back();
      }

      ll ans = a.size();
      for (int i = 0; i < a.size(); i++) {
            ans += a[i];
      }
      cout << ans;
}

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto &i: a) cin >> i;

	if (m == 1) {
            solve(a); return 0;
	}

	// binary search begins

	ll high = 1e16, low = 2;

	while (high != low) {
            ll mid = (high+low)/2;

            vector<ll> b = a;
            ll p = n-1;

            for (int i = 0; i < m; i++) {
                  while (p >= 0 && b[p] == 0) p--;

                  ll t = mid - p - 1;
                  if (t <= 0) break;
                  while (p >= 0 && b[p] <= t) t -= b[p--];
                  if (p >= 0) b[p] -= t;
            }

            if (p < 0) high = mid;
            else low = mid + 1;
	}

	// binary search ends

	cout << low;

	return 0;
}