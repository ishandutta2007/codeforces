#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7; 
int n;
struct rw {
	int a, b, id;
} s[N];
template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		memset(a, 0, sizeof(a));
	}
} ;
fenwt < N > S;
int dp[N], mp[N];
bool vis[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> s[i].a >> s[i].b, s[i].id = i;
	sort(s + 1, s + n + 1, [&] (rw a, rw b) {
		return a.a < b.a;
	});
	L(i, 1, n) mp[s[i].id] = i; 
	R(i, n, 1) {
		dp[i] = 1;
		(dp[i] += S.query (s[i].b) % mod) %= mod;
		S.add (s[i].b, dp[i]); 
	}
	int q;
	cin >> q;
	int mx = 0, cmx = 0;
	while (q--) {
		int x;
		cin >> x, x = mp[x];
		vis[x] = 1;	
		mx = max(mx, s[x].b);
		cmx = max(cmx, x);
	}
	S.clear (); 
	int ns = 0;
	R(i, n, 1) {
		if(vis[i]) 
			S.add(s[i].b, 1);
		if(S.get (s[i].b, N) > 0) 
			(ns += dp[i]) %= mod; 	
	}
	cout << ns << '\n';
	return 0;
}