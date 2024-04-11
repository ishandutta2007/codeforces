#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 107;
int n, xn;
bitset < N > f[N][N];
char s[N];
vi e[N];
void dfs(vi S) {
	int n = sz(S);
	if(n == 1) return ;
	if(n == 2) return e[S[0]].emplace_back(S[1]), e[S[1]].emplace_back(S[0]), void ();
	bitset < N > cur, xcur;
	for(const int &u : S) cur.set(u);
	int rt = 0;
	for(const int &u : S) {
		bitset < N > p = cur;
		for(const int &x : S) if(x != u) for(const int &y : S) 
			if(x < y && x != u && y != u && f[x][y][u]) p &= f[x][y] & cur;
		if(p.count() != 1) {
			rt = u;
			break ;
		}
	}
	if(!rt) return ; 
	vi qwq;
	for(const int &u : S) if(u != rt) qwq.emplace_back(u);
	dfs(qwq);
	for(const int &u : qwq) if(sz(e[u]) && f[rt][e[u][0]][u]) e[u].emplace_back(rt), e[rt].emplace_back(u);
}
int dist[N][N]; 
void Main () {
	cin >> n, xn = n;
	L(i, 0, n) e[i].clear();
	L(i, 1, n) {
		L(j, i + 1, n) {
			cin >> (s + 1);
			L(k, 1, n) f[i][j][k] = s[k] - '0';
			f[j][i] = f[i][j];
		}
	}
	vi G;
	L(i, 1, n) G.emplace_back(i);
	dfs(G);
	L(i, 1, n) L(j, 1, n) dist[i][j] = (i == j) ? 0 : 1e9;
	L(u, 1, n) for(const int &v : e[u]) dist[u][v] = 1;
	L(k, 1, n) L(i, 1, n) L(j, 1, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	L(i, 1, n) L(j, i + 1, n) {
		if(dist[i][j] > n) return cout << "No\n", void ();
		L(k, 1, n) {
			int c = f[i][j][k];
			if(c != (dist[i][k] == dist[j][k])) return cout << "No\n", void ();
		}
	}
	cout << "Yes\n";
	L(u, 1, n) for(const int &v : e[u]) if(u < v) cout << u << ' ' << v << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}