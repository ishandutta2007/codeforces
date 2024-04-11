#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 6e5 + 7, mod = 998244353;
int n;
int ehd[N], ev[N], enx[N], eid; 
void eadd (int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int siz[N], mp[N], sum[N];
void dfs (int x, int fa) {
	siz[x] = 1;
	for(int i = ehd[x]; i; i = enx[i]) if(fa != ev[i]) dfs (ev[i], x), siz[x] += siz[ev[i]];
	mp[siz[x]] ++, mp[siz[x] - 1] ++;
}
int s[N], tp = 0;
void Main () {
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd (u, v), eadd (v, u); 
	}
	L(i, 0, n) sum[i] = mp[i] = 0;
	dfs (1, 0);
	tp = 0;
	L(i, 1, n) if((n - 1) % i == 0) s[++tp] = i; 
	L(i, 2, tp) {
		int res = 0;
		L(j, 0, n / s[i]) (res += mp[s[i] * j]) %= mod;
		sum[s[i]] = res == n;
	}
	sum[1] = 1;
	L(i, 1, n - 1) sum[1] = (ll) sum[1] * 2 % mod;
	R(i, tp, 1) L(j, i + 1, tp) if(s[j] % s[i] == 0) (sum[s[i]] += mod - sum[s[j]]) %= mod;
	L(i, 1, n) cout << sum[i] << " ";
	cout << "\n";
	
	L(i, 1, n) ehd[i] = 0;
	eid = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}