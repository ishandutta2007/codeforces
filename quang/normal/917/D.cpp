#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int MOD = 1000000007;
inline int add(int u, int v) {u += v; if (u >= MOD) u -= MOD; return u;}
inline int sub(int u, int v) {u -= v; if (u < 0) u += MOD; return u;}
inline int mul(int u, int v) {return (long long)u * v % MOD;};
inline int power(int u, int v) {int res = 1; while (v) {if (v & 1) res = mul(res, u); u = mul(u, u); v >>= 1;} return res;}
inline int rev(int u) {return power(u, MOD - 2);}

int n;
vector<int> a[N];
int dp[N][N][N];
int temp[N][N];
int child[N];
int b[N];

void dfs(int u, int p) {	
	dp[u][1][0] = 1;
	child[u] = 1;
	for (int v : a[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u);
		for (int j = child[u] - 1; j >= 0; j--) {
			for (int i = child[u]; i > 0; i--) {
				for (int jj = child[v] - 1; jj >= 0; jj--) {
					for (int ii = child[v]; ii > 0; ii--) {
						temp[i][j + jj] = add(temp[i][j + jj], mul(dp[u][i][j], mul(dp[v][ii][jj], ii)));
						temp[i + ii][j + jj + 1] = add(temp[i + ii][j + jj + 1], mul(dp[u][i][j], dp[v][ii][jj]));
					}
				}
			}
		}
		for (int i = 0; i <= child[u] + child[v]; i++) {
			for (int j = 0; j < child[u] + child[v]; j++) {
				dp[u][i][j] = temp[i][j];
				temp[i][j] = 0;
			}
		}
		child[u] += child[v];
	}
}

int res[N];
int c[N][N];

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b[i] = add(b[i], mul(j, dp[1][j][i]));
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			} else {
				c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
			}
		}
	}
	res[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		res[i] = mul(b[i], power(n, n - i - 2));
		for (int j = i + 1; j < n; j++) {
			res[i] = sub(res[i], mul(c[j][i], res[j]));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;	
}