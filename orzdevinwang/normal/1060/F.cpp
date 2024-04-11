#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 55;
int n, siz[N];
vi e[N];
double f[N][N], sav[N], C[N][N], fac[N];
void dfs(int x, int fa) {
	siz[x] = 0, f[x][0] = 1;
	for(const int &v : e[x]) if(v != fa) {
		dfs(v, x), ++siz[v];
		double sum = 0, o;
		L(a, 0, siz[v]) o = f[v][a], f[v][a] = f[v][a] * (siz[v] - a) + sum / 2, sum += o;
		L(a, 0, siz[x]) L(b, 0, siz[v]) sav[a + b] += C[a + b][a] * C[(siz[x] - a) + (siz[v] - b)][siz[x] - a] * f[x][a] * f[v][b];
		siz[x] += siz[v];
		L(a, 0, siz[x]) f[x][a] = sav[a], sav[a] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); cout.precision(12), cout << fixed;
	cin >> n;
	fac[0] = C[0][0] = 1;
	L(i, 1, n) fac[i] = fac[i - 1] * i, C[i][0] = 1;
	L(i, 1, n) L(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	L(i, 1, n) memset(f, 0, sizeof(f)), dfs(i, -1), cout << f[i][n - 1] / fac[n - 1] << "\n";
	return 0;
}