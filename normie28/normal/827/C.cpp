
// Problem : C. DNA Evolution
// Contest : Codeforces - Codeforces Round #423 (Div. 1, rated, based on VK Cup Finals)
// URL : https://codeforces.com/problemset/problem/827/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j,q;
string s;
struct fen {
	int n; vector<int> t;
	fen(int _n) { n = _n; t.resize(n, 0); }
	void upd(int v, int x) { for(int i = v; i < n; i |= i + 1) t[i] += x; }
	int pref(int v) { int res = 0; for(int i = v; i >= 0; i = (i & (i + 1)) - 1) res += t[i]; return res; }
	int seg(int l, int r) { return pref(r) - pref(l - 1); }
};
int f(char c) { return c == 'A' ? 0 : c == 'T' ? 1 : c == 'G' ? 2 : 3; }
int main() {
	fio;
	cin >> s >> q; 
	n = s.size();
	vector<vector<vector<fen>>> t(4, vector<vector<fen>>(10, vector<fen>(10, fen(n))));
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < 10; j++) 
			t[f(s[i])][j][i % (j + 1)].upd(i, 1);
	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int x; char c; cin >> x >> c; --x;
			for(int i = 0; i < 10; i++) t[f(s[x])][i][x % (i + 1)].upd(x, -1);
			for(int i = 0; i < 10; i++) t[f(c)][i][x % (i + 1)].upd(x, 1);
			s[x] = c;
		} else {
			int l, r; string e; cin >> l >> r >> e; --l; --r; int len = e.size(), ans = 0;
			for(int i = 0; i < len && l + i <= r; i++) {
				ans += t[f(e[i])][len - 1][(l + i) % len].seg(l + i, n - 1) 
				- (r < n - 1 ? t[f(e[i])][len - 1][(l + i) % len].seg(r + 1, n - 1) : 0);\
			}
			cout << ans << endl;
		}
	}
}