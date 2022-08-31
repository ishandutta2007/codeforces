#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7, K = 42;
int n, k, sk;
ll cnt[N][K], p[K], a[N];
vi e[N];
void dfs(int x, int fa = 0) {
	cnt[x][0] ^= a[x];
	for(int v : e[x]) if(v != fa) {
		dfs(v, x);
		L(i, 0, sk - 1) cnt[x][(i + 1) % sk] ^= cnt[v][i];
	}
}
void dfs2(int x, int fa = 0) {
	for(int v : e[x]) if(v != fa) {
		L(i, 0, sk - 1) p[(i + 2) % sk] ^= cnt[x][(i + 1) % sk] ^ cnt[v][i];
		L(i, 0, sk - 1) cnt[v][i] ^= p[i], p[i] = 0;
		dfs2(v, x);
	}
}
void Main() {
	cin >> n >> k, sk = k * 2;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	L(i, 1, n) cin >> a[i];
	dfs(1, 0), dfs2(1, 0);
	L(i, 1, n) {
		int SG = 0;
		L(j, k, sk - 1) SG ^= cnt[i][j];
		cout << (!!SG) << " ";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}