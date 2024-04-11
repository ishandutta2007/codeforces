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

int n, k, s;
ll q[150];

void solve() {
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}

	if (n * n <= s) {
		sort(q, q + n);

		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans += q[i];
		}

		cout << ans << endl;
		return;
	}

	vector<vector<ll>> prev(k + 1, vector<ll>(s + 1));
	vector<vector<ll>> curr(k + 1, vector<ll>(s + 1));

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= s; j++) {
			prev[i][j] = INF;
		}
	}

	prev[1][0] = q[0];
	prev[0][0] = 0;

	for (int f = 1; f < n; f++) {
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= s; j++) {
				curr[i][j] = prev[i][j]; // don't use f'th element

				if (i > 0) { // use f'th element
					int cost = abs(f - (i - 1));
					if (j - cost >= 0) {
						curr[i][j] = min(prev[i][j], prev[i - 1][j - cost] + q[f]);
					}
				}
			}
		}

		swap(curr, prev);
	}

	cout << *min_element(prev[k].begin(), prev[k].end()) << endl;
}

int main() {
	//freopen("tree.in", "r", stdin);
	//freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}