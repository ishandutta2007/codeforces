#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 310;

struct Node {
	int s, id;
}	e[N * N];

int operator < (Node A, Node B) {
	if (A.s == B.s) return A.id < B.id;
	return A.s < B.s;
}

int T, n, m;
Node f[N][N];
vector <Node> v;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n >> m; v.clear();
		for (int i = 1; i <= n * m; i++) {
			int a; cin >> a;
			v.push_back((Node){a, i});
		}
		sort (v.begin(), v.end());
		int c = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				f[i][j] = v[c++];
		for (int i = 1; i <= n; i++) {
			int lst = 1;
			for (int j = 2; j <= m; j++)
				if (f[i][j].s != f[i][lst].s) {
					reverse(f[i] + lst, f[i] + j);
					lst = j;
				}
			reverse(f[i] + lst, f[i] + m + 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int k = 1; k < j; k++)
					if (f[i][j].id > f[i][k].id)
						ans++;
		cout << ans << endl;
	}
	return 0;
}