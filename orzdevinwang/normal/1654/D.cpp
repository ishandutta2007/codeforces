#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, M = 2e5, T = N * 20, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

int n, m, hd[N];
vi fac[M + 7];

int mx[N], cur[N]; 
int lk[N];

vector < pair < int, pair < int, int > > > e[N];
void dfs(int x, int fa) {
	lk[x] = 1;
	for(auto v : e[x]) if(v.first != fa) {
		int a = v.second.first, b = v.second.second;
		swap(a, b);
		
		for(const int &u : fac[a]) cur[u] -= 1;	
		for(const int &u : fac[b]) cur[u] += 1, mx[u] = max(mx[u], cur[u]);	
//		cout << "V = " << v.first << '\n';
		dfs(v.first, x); 
		(lk[x] += (ll) lk[v.first] * a % mod * qpow(b) % mod) %= mod;
		
		for(const int &u : fac[a]) cur[u] += 1;
		for(const int &u : fac[b]) cur[u] -= 1;	
	}
}

void Main() {
	cin >> n ;
	L(i, 1, n) e[i].clear(), mx[i] = cur[i] = 0;
	L(i, 1, n - 1) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		e[u].push_back(make_pair(v, make_pair(x, y)));
		e[v].push_back(make_pair(u, make_pair(y, x)));
	}
//	cout << "SZ = " << sz(e[1]) << '\n';
	dfs(1, 0);
	int now = lk[1];
//	cout << "lk = " << lk[1] << '\n';
	L(i, 1, n) L(j, 1, mx[i]) now = (ll) now * i % mod;
	cout << now << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 2, M) if(!sz(fac[i])) 
		for(ll t = i; t <= M; t *= i)
			for(int j = t; j <= M; j += t) 
				fac[j].emplace_back(i);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}