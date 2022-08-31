#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, p[N], a[N], le[N];
ll sum[N], mx[N];
vector<int> g[N];

void dfs(int x) {
	if (g[x].empty()) {
		le[x] = 1;
		mx[x] = a[x];
		sum[x] = a[x];
		return;
	}
	sum[x] = a[x];
	for (int i : g[x]) {
		dfs(i);
		le[x] += le[i];
		mx[x] = max(mx[x], mx[i]);
		sum[x] += sum[i];
	}
	mx[x] = max(mx[x], (sum[x] + le[x] - 1) / le[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << mx[1] << '\n';
	return 0;
}