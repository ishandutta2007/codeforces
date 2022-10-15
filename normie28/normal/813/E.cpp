
// Problem : E. Army Creation
// Contest : Codeforces - Educational Codeforces Round 22
// URL : https://codeforces.com/problemset/problem/813/E
// Memory Limit : 256 MB
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
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
//---------END-------//
 
int N, K, NR=1, a[100100], g[100100], root[100100], Q, lst;
vector<int> c[100100];
 
struct range {
	int l, r, sum;
} r[4400400];
 
int u (int i, int rs, int re, int p, int d) {
	int n = ++NR; r[n] = r[i];
	if (rs == re-1) r[n].sum += d;
	else {
		int m = (rs+re)/2;
		if (p<m) r[n].l = u(r[n].l, rs, m, p, d);
		else r[n].r = u(r[n].r, m, re, p, d);
		r[n].sum = r[r[n].l].sum + r[r[n].r].sum;
	}
	return n;
}
 
int q (int i, int rs, int re, int qs, int qe) {
	if (rs == qs && re == qe) return r[i].sum;
	int m = (rs+re)/2, n = 0;
	if (qs<m && r[i].l) n += q(r[i].l, rs, m, qs, min(m, qe));
	if (qe>m && r[i].r) n += q(r[i].r, m, re, max(qs, m), qe);
	return n;
}
 
int main () {
	fio;
	cin>>N>>K;
	fo(i, 1, N+1) {
		cin>>a[i];
		c[a[i]].PB(i);
	}
	fo(i, 1, 100100) {
		for (int j = 0; j+K < SZ(c[i]); j++) {
			g[c[i][j]] = c[i][j+K];
		}
	}
 
	root[N+1] = 1;
	for (int i = N; i >= 1; i--) {
		root[i] = u(root[i+1], 1, N+1, i, 1);
		if (g[i]) root[i] = u(root[i], 1, N+1, g[i], -1);
	}
 
 cin>>Q;
	fo(z, 0, Q) {
		int x, y; cin>>x>>y;
		x = (x + lst) % N + 1, y = (y + lst) % N + 1;
		if (x>y) swap(x, y);
 
		lst = q(root[x], 1, N+1, x, y+1);
		cout<<lst<<endl;
	}
}