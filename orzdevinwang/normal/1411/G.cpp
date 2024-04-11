#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7, M = 555, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int f[M][M];
void Guess() {
	L(i, 0, 511) {
		int cs = -1;
		L(j, i, 511) if(f[j][i]) cs = j;
		swap(f[i], f[cs]);
		int Iv = qpow(f[i][i]);
		L(j, 0, 511) if(j != i) {
			int t = mod - (ll) f[j][i] * Iv % mod;
			L(k, i, 512) (f[j][k] += (ll) t * f[i][k] % mod) %= mod;
		}
	}
	L(i, 0, 511) f[i][512] = (ll) f[i][512] * qpow(f[i][i]) % mod, f[i][i] = 1;
} 
int n, m, deg[N];
vector<int> e[N], se[N];
int mp[N], cnt[N], ns[N];
void topo() {
	queue<int> q;
	L(i, 1, n) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front();
//		cout << " = " << u << "\n";
		for(int v : e[u]) ++ mp[ns[v]];
		while(mp[ns[u]]) ++ ns[u];
		for(int v : e[u]) -- mp[ns[v]];
		q.pop();
		for(int v : se[u]) {
			-- deg[v];
			if(! deg[v]) q.push(v);
		}
	}
	L(i, 1, n) ++ mp[ns[i]]; //, cout << ns[i] << "\n";
//	L(i, 0, 3) cout << mp[i] << ", ";
//	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
//	cout << (ll) (mod + 1 - 931694730) * 15 % mod << "\n";
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), se[v].push_back(u), deg[u] ++;
	}
	topo();
	L(i, 0, 511) L(j, 0, 511) (f[i][j] += mod - mp[i ^ j]) %= mod;
	L(i, 0, 511) (f[i][i] += n + 1) %= mod;
//	L(i, 0, 3) L(j, 0, 3) cout << setw(10) << f[i][j] << " \n"[j == 3];
//	cout << f[0][0] << "\n";
	f[0][512] = 1, Guess();
	cout << (mod + 1 - f[0][512]) % mod << "\n";
	
//	cout << "\n\n";
//	L(i, 0, 10) cout << f[i][512] << ",\n";
	return 0;
}