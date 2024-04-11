
// Problem : C. Serge and Dining Room
// Contest : Codeforces - Codeforces Round #569 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1179/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
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
const int LIMIT = 1000010;
 
int N, M;
long long tr[4 * LIMIT], lz[4 * LIMIT];
int A[400000], B[400000];
 
void push_down (int n, int l, int r) {
	if (l < r) {
		int m = l + r >> 1;
		tr[n << 1] += lz[n];
		lz[n << 1] += lz[n];
		tr[n << 1 | 1] += lz[n];
		lz[n << 1 | 1] += lz[n];
	}
	lz[n] = 0;
}
 
void add (int n, int l, int r, int ql, int qr, int d) {
	push_down (n, l, r);
	if (ql <= l && r <= qr) {
		tr[n] += d;
		lz[n] += d;
		return;
	}
	int m = l + r >> 1;
	if (ql <= m) add (n << 1, l, m, ql, qr, d);
	if (m + 1 <= qr) add (n << 1 | 1, m + 1, r, ql, qr, d);
	tr[n] = std::max (tr[n << 1], tr[n << 1 | 1]);
}
 
int query (int n, int l, int r) {
	push_down (n, l, r);
	if (l == r) return l;
	int m = l + r >> 1;
	if (tr[n << 1 | 1] > 0) return query (n << 1 | 1, m + 1, r);
	return query (n << 1, l, m);
}
 
int main () {
	fio;
	cin>>N>>M;
	for (int i = 1; i <= N; ++i) cin>>A[i], add (1, 1, LIMIT, 1, A[i], 1);
	for (int i = 1; i <= M; ++i) cin>>B[i], add (1, 1, LIMIT, 1, B[i], -1);
	int Q; cin>>Q;
	for (int i = 1; i <= Q; ++i) {
		int op, ind, nval; cin>>op>>ind>>nval;
		if (op == 1) {
			add (1, 1, LIMIT, 1, A[ind], -1);
			A[ind] = nval;
			add (1, 1, LIMIT, 1, A[ind], 1);
		} else {
			add (1, 1, LIMIT, 1, B[ind], 1);
			B[ind] = nval;
			add (1, 1, LIMIT, 1, B[ind], -1);
		}
		if (tr[1] <= 0) cout<<-1<<endl;
		else cout<<query(1, 1, LIMIT)<<endl;
	}
}