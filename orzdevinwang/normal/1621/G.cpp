#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define sz(a) ((int) a.size())
#define vi vector<int>
#define ll long long
#define me(f, x) memset(f, x, sizeof(f))  
#define ull unsigned long long 
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
template < int N > struct fenwt {
	using F = int ;
	int n;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= n; x += x & -x) (a[x] += w) %= mod;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) (ret += a[x]) %= mod; 
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return (query (r) + mod - query (l - 1)) % mod;
	}
	void clear () {
		memset(a, 0, sizeof(F) * (n + 1));
	}
} ;
fenwt < N > fw[3];
int n, a[N], mp[N];
struct pr {
	int x, p;
} ar[N];
int stk[N], tp;
int col[N];
bool vis[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i], ar[i].p = i, ar[i].x = a[i];
	sort(ar + 1, ar + n + 1, [&] (pr a, pr b) { return a.x == b.x ? a.p > b.p : a.x < b.x; });
	L(i, 1, n) a[ar[i].p] = i, mp[i] = ar[i].p;
	tp = 0;
	R(i, n, 1) if(a[i] > stk[tp]) stk[++tp] = a[i];
	L(i, 1, tp) L(j, stk[i - 1] + 1, stk[i]) col[j] = i; 
	L(o, 0, 2) fw[o].n = n;
	R(i, n, 1) {
		int p = col[a[i]];
		
		fw[2].add (a[i], fw[2].get (a[i], n));
		
		fw[2].add (a[i], fw[1].get (a[i], n));
		fw[1].add (a[i], fw[1].get (a[i], n));
		
		fw[1].add (a[i], fw[0].get (stk[p] + 1, n));
		fw[2].add (a[i], fw[0].get (stk[p] + 1, n));
		fw[0].add (a[i], fw[0].get (a[i], stk[p])); 
		
		if(stk[p] == a[i]) {
			fw[1].add(a[i], 1);
			fw[0].add (a[i], 1);
			if(p > 1) fw[1].add (stk[p - 1], -1);
		} 
	} 
	cout << fw[2].query(n) << '\n';
	L(o, 0, 2) fw[o].clear ();
} 
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while (t--) Main ();
	return 0;
} 
/*
1
4
1 2 3 4
*/