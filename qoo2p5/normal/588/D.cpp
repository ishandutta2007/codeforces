#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const ll mod = 1e9 + 7;

int n, k;
ll l;
vector<int> a;
vector<pair<int, int>> b;
vector<int> ind;
vector<vector<ll>> d;

void solve() {
	cin >> n >> l >> k;
	a.resize(n);
	b.resize(n);
	ind.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = mp(a[i], i);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < sz(b); i++) {
		ind[b[i].second] = i;
	}

	d.resize(n, vector<ll>(k + 1));
	for (int i = 0; i < n; i++) {
		d[i][1] = 1;
	}

	for (int j = 2; j <= k; j++) {
		ll sum = 0;
		int p = 0;

		for (int i = 0; i < n; i++) {
			while (p < n && a[p] <= a[i]) {
				sum += d[p][j - 1];
				p++;
			}

			sum %= mod;
			d[i][j] = sum;
		}
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			ll p = l / n;
			if (i < l % n) {
				p++;
			}

			ll f = p - j + 1;
			if (f > 0) {
				f %= mod;
				ans += (d[ind[i]][j] * f) % mod;
				ans %= mod;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}