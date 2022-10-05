#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
int a[13][2005];

int ssum(multiset<int> &A) {
	int ans = 0;
	auto it = A.rbegin();
	for (int i = 0; i < 3; i++)
		ans += *it, it++;
	return ans;
}

void solve() {
	cin >> n >> m;
	vector<int> val;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], val.push_back(a[i][j]);
	sort(val.rbegin(), val.rend());
	if (n <= 3) {
		int ans = 0;
		for (int i = 0; i < n; i++) ans += val[i];
		cout << ans << '\n';
		return;
	}
	if (m == 1) {
		int ans = 0;
		for (auto &i : val) ans += i;
		cout << ans << '\n';
		return;
	}
	int ans = 0;
	multiset<int> S;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) S.insert(a[i][j]);
	for (int j = 0; j < m; j++) {
		int sum = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i][j];
			mx = max(mx, a[i][j]);
		}
		ans = max(ans, sum);
		for (int i = 0; i < 4; i++)
			S.erase(S.find(a[i][j]));
		ans = max(ans, mx + ssum(S));
		for (int i = 0; i < 4; i++)
			S.insert(a[i][j]);
	}
	
	vector<int> opp, adj;
	for (int j = 0; j < m; j++) {
		int mx1 = 0, mx2 = 0;
		for (int i = 0; i < n; i++) {
			mx1 = max(mx1, a[i][j] + a[(i + 1) % n][j]);
			mx2 = max(mx2, a[i][j] + a[(i + 2) % n][j]);
		}
		adj.push_back(mx1);
		opp.push_back(mx2);
	}
	sort(adj.rbegin(), adj.rend());
	sort(opp.rbegin(), opp.rend());
	ans = max(ans, adj[0] + adj[1]);
	ans = max(ans, opp[0] + opp[1]);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}