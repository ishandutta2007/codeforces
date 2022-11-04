#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

const int N = 1000;

int n, k;
bool a[N];
string ans[N];
vector<int> g[N];

string cur = "A";

void gen() {
	if (cur == "Z") {
		cur = "Aa";
	} else {
		cur[0]++;
	}
}

void dfs(int v) {
	for (int u : g[v]) {
		if (ans[u].empty()) {
			ans[u] = ans[v];
			dfs(u);
		}
	}
}

void run() {
	cin >> n >> k;
	for (int i = 0; i < n - k + 1; i++) {
		string s;
		cin >> s;
		a[i] = (s == "YES");
	}
	
	for (int i = 0; i < n - k + 1; i++) {
		if (!a[i]) {
			g[i].pb(i + k - 1);
			g[i + k - 1].pb(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (ans[i].empty()) {
			ans[i] = cur;
			gen();
			dfs(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}