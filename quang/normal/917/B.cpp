#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
vector<pair<int, char> > a[N];
int dp[30][N][N];

bool go(int last, int u, int v) {
	if (dp[last][u][v] != -1) {
		return dp[last][u][v];
	}
	int res = 0;
	for (pair<int, char> w : a[u]) {
		if (w.second - 'a' >= last) {
			int foo = go(w.second - 'a', v, w.first);
			if (!foo) {
				res = 1;
				break;
			}
		}
	}
	return dp[last][u][v] = res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		char x;
		cin >> u >> v >> x;
		a[u].push_back(make_pair(v, x));
	}
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (go(0, i, j)) {
				cout << "A";
			} else {
				cout << "B";
			}
		}
		cout << endl;
	}
	return 0;
}