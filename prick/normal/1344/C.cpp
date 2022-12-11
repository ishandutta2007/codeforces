#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int maxn = 2e5 + 42;

int n, m;
vector<int> graph[maxn];
vector<int> rev[maxn];
int color[maxn];
vector<int> order;

void fail() {
	cout << "-1\n";
	exit(0);
}

void dfs(int v) {
	if (color[v] == 2) return;
	if (color[v] == 1) fail();
	color[v] = 1;
	for (auto to: graph[v]) {
		dfs(to);
	}
	order.push_back(v);
	color[v] = 2;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rev[b].push_back(a);
	}
	
	for (int i = 1; i <= n; ++i) {
		dfs(i);
	}
	vector<int> revorder = order;
	reverse(order.begin(), order.end());
	
	vector<int> in(n + 1, n + 100500);
	vector<int> out(n + 1, n + 100500);
	for (auto v: order) {
		int upd = min(v, in[v]);
		for (auto to: graph[v]) {
			in[to] = min(in[to], upd);
		}
	}
	for (auto v: revorder) {
		int upd = min(v, out[v]);
		for (auto to: rev[v]) {
			out[to] = min(out[to], upd);
		}
	}
	
	string ans;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (i < in[i] && i < out[i]) {
			ans.push_back('A');
			++cnt;
		} else {
			ans.push_back('E');
		}
	}
	
	cout << cnt << '\n';
	cout << ans << '\n';
}