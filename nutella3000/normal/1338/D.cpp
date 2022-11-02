#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e5 + 5;
int n;
vector<int> gr[max_n];
int dp[max_n][2];
int answer = 0;

int f(vector<int> a, vector<int> b) {
	int res = 0;
	int b_max = b[0];
	for(int i = 1;i < sz(a);i++) {
		b_max = max(b_max, b[i - 1]);
		res = max(res, b_max + a[i]);
	}
	return res;
}

void dfs(int v, int pr) {
	//cout << "vertex: " << v << endl;
	if (gr[v].size() == 1 && pr != -1) {
		dp[v][0] = 0;
		dp[v][1] = 1;
		return;
	}

	for(int i : gr[v]) {
		if (i == pr) continue;
		dfs(i, v);

		dp[v][0] = max(dp[v][0], dp[i][1] + sz(gr[v]) - 2 + (pr == -1 ? 1 : 0));
		dp[v][1] = max(dp[v][1], dp[i][0] + 1);
	}

	dp[v][1] = max(dp[v][1], dp[v][0]);

	//cout << v + 1 << " " << dp[v][0] << " " << dp[v][1] << endl;


	answer = max(answer, dp[v][1]);

	if (gr[v].size() == 2 && pr != -1) return;
	if (gr[v].size() == 1) return;

	vector<int> a, b;

	for(int i : gr[v]) {
		if (i == pr) continue;
		a.emplace_back(dp[i][1]);
		b.emplace_back(dp[i][1]);
	}

	answer = max(answer, f(a, b) + sz(gr[v]) - 2);
	a.clear();
	b.clear();

	for(int i : gr[v]) {
		if (i == pr) continue;
		a.emplace_back(dp[i][0]);
		b.emplace_back(dp[i][0]);
	}

	answer = max(answer, f(a, b) + 1);
}


void solve() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}

	dfs(0, -1);

	cout << answer;
}


 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);
 
   	solve();
 
}