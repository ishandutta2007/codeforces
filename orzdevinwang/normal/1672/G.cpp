#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 4007, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, m, k;
int cnta[N], cntb[N]; 
bool vis[N][N];
char s[N][N];
int opa[N], opb[N];
bool gta[N], gtb[N];
int ns;

vi e[N];
int all, cnt;
bool oc[N]; 
void dfs(int x, int fa) {
	all ^= opa[x], oc[x] = true;
	for(const int &v : e[x]) if(oc[v] && v != fa) cnt += 1;
	for(const int &v : e[x]) if(!oc[v]) dfs(v, x);
}
int h[N];

void slv(int W) {
	me(oc, 0);
	me(cnta, 0);
	me(cntb, 0);
	L(i, 1, n + m) opa[i] = W, e[i].clear(); 
	L(i, 1, n) {
		L(j, 1, m) {
			if(s[i][j] == '?') {
				e[i].emplace_back(j + n);
				e[j + n].emplace_back(i);
			} else {
				int w = s[i][j] - '0';
				opa[i] ^= w;
				opa[j + n] ^= w;
			}
		}
	}
	cnt = 0;
	L(i, 1, n + m) 
		if(!oc[i]) {
			all = 0;
			dfs(i, 0);
			if(all) return ;
		}
	(ns += qpow(2, cnt)) %= mod;
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 1, n) {
		cin >> (s[i] + 1);
		L(j, 1, m) 
			if(s[i][j] == '?') 
				++k;
	}
	if(n % 2 == 0 && m % 2 == 0) {
		cout << qpow(2, k) << '\n';
		return 0;
	}
	if(n % 2 == 1 && m % 2 == 1) {
		L(W, 0, 1) {
			slv(W);
		}
		cout << ns << '\n';
	} else if(m % 2 == 1) {
		L(W, 0, 1) {
			int rns = 1;
			L(i, 1, n) {
				int sum = W, cnt = 0;
				L(j, 1, m) {
					if(s[i][j] == '?') cnt += 1;
					else sum ^= s[i][j] - '0';
				}
				if(cnt == 0) {
					if(!sum) {
						rns = 0;
						break ;
					}
				} else {
					rns = (ll) rns * qpow(2, cnt - 1) % mod;
				}
			}
			(ns += rns) %= mod;
		}
		cout << ns << '\n';
	} else {
		L(W, 0, 1) {
			int rns = 1;
			L(j, 1, m) {
				int sum = W, cnt = 0;
				L(i, 1, n) {
					if(s[i][j] == '?') cnt += 1;
					else sum ^= s[i][j] - '0';
				}
				if(cnt == 0) {
					if(!sum) {
						rns = 0;
						break ;
					}
				} else {
					rns = (ll) rns * qpow(2, cnt - 1) % mod;
				}
			}
			(ns += rns) %= mod;
		}
		cout << ns << '\n';
	}
	return 0;
}