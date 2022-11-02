#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 10;

vector<int> d(maxn);
vector<int> g[maxn];
vector<int> used(maxn);
vector<pair<int, int>> c(maxn);
vector<int> color(maxn);
vector<pair<int, int>> r;
int cnt = 0, mx = 0, cn = 0, cn1 = 0;
void dfs(int v) {
	used[v] = true;
	for (auto to : g[v]) {
		if (!used[to]) {
			d[to] = d[v] + 1;
			mx = max(d[v] + 1, mx);
			dfs(to);
		}
	}
}

void dfs1(int v) {
	c[v].first = 0;
	c[v].second = 0;
	if (color[v] == 1) c[v].first++;
	if (color[v] == 2) c[v].second++;
	used[v] = true;
	for (auto to : g[v]) {
		if (!used[to]) {
			dfs1(to);
			c[v].first += c[to].first;
			c[v].second += c[to].second;
		}
	}
}



int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];

	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[b].pb(a);
		g[a].pb(b);
		r.pb(make_pair(a, b));
	}
	dfs1(1);
	fill(used.begin(), used.end(), 0);
	dfs(1);
	for (int i = 2; i <= n; i++){
		int a = r[i - 2].first;
		int b = r[i - 2].second;
		int c1;
		if (d[a] > d[b]) {
			c1 = a;
		}
		else {
			c1 = b;
		}
		if ((c[1].first - c[c1].first == 0 || c[1].second - c[c1].second == 0) && (c[c1].first == 0 || c[c1].second == 0)) {
			cnt++;
		}
	}
	cout << cnt;
}