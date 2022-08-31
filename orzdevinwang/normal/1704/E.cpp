#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m, a[N], deg[N], xu[N], xv[N]; 
vi e[N];
bool ok[N];
int ord[N], tot;
void topo() {
	queue < int > q;
	L(i, 1, n) 
		if(!deg[i]) q.push(i);
	L(t, 1, n) {
		int u = q.front();
		q.pop();
		ord[t] = u;
		for(const int &v : e[u]) {
			deg[v] -= 1;
			if(!deg[v]) q.push(v);
		}
	}
}
inline int slv() {
	int ns = 0;
	return ns;
}
void Main() {
	cin >> n >> m;
	L(i, 1, n) e[i].clear(), deg[i] = 0, ok[i] = false;
	L(i, 1, n) cin >> a[i], ok[i] = a[i] >= mod, a[i] %= mod;
	L(i, 1, m) cin >> xu[i] >> xv[i], deg[xv[i]] += 1, e[xu[i]].emplace_back(xv[i]);
	topo();
	L(t, 1, 2 * n) {
		bool qwq = false;
		L(i, 1, n) if(a[i] || ok[i]) qwq = true;
		if(!qwq) {
			cout << t - 1 << '\n';
			return ;
		}
		R(i, n, 1) {
			int u = ord[i];
			if(a[u] > 0 || ok[u]) {
				(a[u] += mod - 1) %= mod;
				for(const int &v : e[u]) {
					if(a[v] == mod - 1) 
						ok[v] = true;
					(a[v] += 1) %= mod;
				}
			}
		}
	}
	L(i, 1, n) {
		int u = ord[i];
		for(const int &v : e[u]) 
			(a[v] += a[u]) %= mod; 
	}
	cout << (2 * n + a[ord[n]]) % mod << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}