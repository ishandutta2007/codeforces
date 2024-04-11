#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5, mx = 2e5;
int n;
int a[sz], dp[sz];
int frind[sz], lind[sz];
vector<int> adj[sz];

void updateAdj(int i) {
	for (ll x = 1; x * x <= a[i]; x++) {
		if (a[i] % x == 0) {
			if (lind[x] != -1)adj[frind[x]].pb(i);
			if (x != 1 && x*x != a[i]) {
				if (lind[a[i] / x] != -1)adj[frind[a[i] / x]].pb(i);
			}
		}
	}
}

void reset() {
	foru(i, 0, n) {
		adj[i].clear();
		dp[i] = 0;
	}
	foru(i, 0, mx + 1) { frind[i] = lind[i] = -1; };
}

void solve() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	reset();
	sort(a, a + n);
	foru(i, 0, n)frind[a[i]] = i;
	ford(i, n - 1, 0)lind[a[i]] = i;
	ford(i, n - 1, 0) {
		if (a[i] == a[i + 1]) adj[i].pb(i + 1);
		if (i == lind[a[i]] && a[i] != 1) updateAdj(i);
	}
	dp[n - 1] = 1;
	ford(i, n - 2, 0) {
		dp[i] = 1;
		for (int x : adj[i])dp[i] = max(dp[i], 1 + dp[x]);
	}
	int mx = 1;
	foru(i, 0, n)mx = max(mx, dp[i]);
	cout << n - mx << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}