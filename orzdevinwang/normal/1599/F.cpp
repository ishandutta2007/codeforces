#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7, inv6 = (mod + 1) / 6, W = 2;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int sum1 (int x) {
	return (ll) x * (x + 1) / 2 % mod;
}
int sum2 (int x) {
	return (ll) x * (x + 1) % mod * (2 * x + 1) % mod * inv6 % mod;
}
bool vis[N];
int n, m, a[N];
struct fenwk {
	int sz[N];
	void add (int x, int w) {
		for (; x; x -= x & -x) 
			(sz[x] += w) %= mod;
	}
	int query (int x) {
		int ret = 0;
		for (; x <= n; x += x & -x) 
			(ret += sz[x]) %= mod;
		return ret;
	} 
} fw[W + 1];
int L[N], R[N], D[N];
vi q[N];
bool ns[N];

map < int, int > mp;

void Add (int w, int k) {
	int ret = 1;
	L(i, 0, W) fw[i].add(w, (ll) ret * k % mod), ret = (ll) ret * a[w] % mod; 
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, n) {
		cin >> a[i];
	}
	L(i, 1, m) {
		cin >> L[i] >> R[i] >> D[i], q[R[i]].push_back(i);
	}
	L(i, 1, n) {
		int z = mp[a[i]];
		mp[a[i]] = i;
		if(z) Add(z, mod - 1);
		Add (i, 1);
		
		for (const int &t : q[i]) {
			int a = fw[0].query(L[t]), b = fw[1].query(L[t]), fir = (b + mod - (ll) 
			a * (a - 1) / 2 % mod * D[t] % mod) * qpow (a) % mod;
			if(mp[fir] < L[t]) ns[t] = false;
			else {
				int s0 = a, s1 = sum1(a - 1), s2 = sum2 (a - 1);
				int ret = 0;
				(ret += (ll) fir * fir % mod * s0 % mod) %= mod;
				(ret += (ll) 2 * fir * D[t] % mod * s1 % mod) %= mod;
				(ret += (ll) D[t] * D[t] % mod * s2 % mod) %= mod;
				ns[t] = ret == fw[2].query(L[t]);
			}
		}
	}
	L(i, 1, m) {
		if(ns[i]) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}