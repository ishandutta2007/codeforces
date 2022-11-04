#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, k;
vector<ll> s;
vector<ll> used;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	s.resize(n);
	used.resize(k);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	reverse(s.begin(), s.end());

	fill(used.begin(), used.end(), 0);
	for (int i = 0; i < min(n, k); i++) {
		used[i] += s[i];
	}

	if (n <= k) {
		ll ans = 0;
		for (int i = 0; i < k; i++) {
			ans = max(ans, used[i]);
		}

		cout << ans << endl;
		return 0;
	}

	int r = n - k;
	int j = k - r;
	for (int i = n - 1; i >= k; i--, j++) {
		used[j] += s[i];
	}

	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ans = max(ans, used[i]);
	}

	cout << ans << endl;
	return 0;
}