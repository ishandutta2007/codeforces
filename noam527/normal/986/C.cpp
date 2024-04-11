#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

int n, m;
int vis[1 << 22][2] = {};
vector<int> a;

void dfs(int v, int x) {
	if (vis[v][x]) return;
	if (x == 0 && a[v] == 0) return;
	vis[v][x] = 1;
	if (x == 0) {
		dfs((1 << n) - 1 - v, 1);
	}
	else {
		for (int i = 0; i < n; i++)
			if (v & (1 << i))
				dfs(v ^ (1 << i), 1);
		dfs(v, 0);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(1 << n, 0);
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		a[x] = 1;
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
		if (a[i] && !vis[i][0]) dfs(i, 0), ans++;
	finish(ans);
}