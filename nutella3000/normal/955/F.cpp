#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 3e5 + 3;

int n;
vector<int> gr[max_n];
vector<int> dp[max_n];
int mx_k[max_n];

void dfs(int v, int pr) {
	vector<int> ch;
	for(int to : gr[v]) {
		if (to == pr) continue;
		dfs(to, v);
		ch.emplace_back(to);
	}

	vector<vector<int>> a(sz(ch));
	for(int to : ch) {
		for(int i = 0;i < min(sz(ch), mx_k[to]);i++) {
			if (sz(dp[to]) > i)
				a[i].emplace_back(dp[to][i]);
			else a[i].emplace_back(2);
		}
	}

	for(int k = 1;k <= sz(ch);k++) {
		sort(all(a[k - 1]));
		reverse(all(a[k - 1]));
		if (sz(a[k - 1]) > k - 1) dp[v].emplace_back(a[k - 1][k - 1] + 1);
	}
	mx_k[v] = sz(ch);
}


void dfs1(int v, int pr) {
	for(int to : gr[v]) {
		if (to == pr) continue;
		dfs1(to, v);
		for(int k = 0;k < sz(dp[to]);k++) {
			if (sz(dp[v]) == k) dp[v].emplace_back(dp[to][k]);
			else chkmax(dp[v][k], dp[to][k]);
		}
		chkmax(mx_k[v], mx_k[to]);
	}
}

void solve() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}

	dfs(0, -1);
	dfs1(0, -1);

	int res = 0;
	for(int i = 0;i < n;i++) {
		for(int j : dp[i])
			res += j;
		res += (mx_k[i] - sz(dp[i])) * 2 + (n - mx_k[i]);
	}

	cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}