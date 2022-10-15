#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[5555];
int z[5555];
int n1, n2, n3;
int c1, c2;
int k1[5555], k2[5555];
int aa[5555];
int f[5555];

void dfs(int x, int c) {
	if (z[x] == c) return;
	if (z[x]) {
		cout << "NO\n";
		exit(0);
	}
	if (c == 1) c1++;
	else c2++;
	z[x] = c;
	for (auto u : v[x]) {
		dfs(u,3-c);
	}
}

void dfs2(int x, int c) {
	if (f[x]) return;
	f[x] = c;
	for (auto u : v[x]) {
		dfs2(u,3-c);
	}
}

int dd[5555][5555];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (z[i]) continue;
		k++;
		aa[k] = i;
		c1 = c2 = 0;
		dfs(i,1);
		k1[k] = c1;
		k2[k] = c2;
	}
	dd[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n2; j++) {
			if (j-k1[i] >= 0 && dd[i-1][j-k1[i]]) {
				dd[i][j] = 1;
			}
			if (j-k2[i] >= 0 && dd[i-1][j-k2[i]]) {
				dd[i][j] = 2;
			}
		}
	}
	if (!dd[k][n2]) {
		cout << "NO\n";
		return 0;
	}
	int u = n2;
	for (int i = k; i >= 1; i--) {
		if (dd[i][u] == 1) {
			dfs2(aa[i],2);
			u -= k1[i];
		} else {
			dfs2(aa[i],1);
			u -= k2[i];
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1 && n1) n1--;
		else if (f[i] == 1) f[i] = 3;
		cout << f[i];
	}
	cout << "\n";
}