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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "billboard.inp"
#define FILE_OUT "billboard.out"
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
 
const int MAX_N = 2e5 + 10, MAX_K = 1e1 + 1;
int n, m, k;
string S, P;
 
int seg[MAX_N << 2][MAX_K][MAX_K];
int lazy[MAX_N << 2];
 
void merge (int s, int e, int id) {
	memset(seg[id], 0, sizeof seg[id]);
	for (int i = 0; i < MAX_K; i++)
		for (int j = 0; j < MAX_K; j++)
			seg[id][i][j] += seg[id << 1][i][j] + seg[id << 1 | 1][i][j];
 
	int mid = e + s >> 1;
	seg[id][S[mid] - 'a'][S[mid - 1] - 'a']++;
}
 
void build (int s = 0, int e = n, int id = 1) {
	if (e - s == 1)
		return ;
	
	int mid = e + s >> 1;
	build(s, mid, id << 1);
	build(mid, e, id << 1 | 1);
	merge(s, e, id);
}
 
void shift (int s, int e, int id) {
	int mid = e + s >> 1;
 
	memset(seg[id << 1], 0, sizeof seg[id << 1]);
	seg[id << 1][lazy[id] - 1][lazy[id] - 1] = mid - s - 1;
	lazy[id << 1] = lazy[id];
	S[s] = S[mid - 1] = char('a' + lazy[id] - 1);
 
	memset(seg[id << 1 | 1], 0, sizeof seg[id << 1 | 1]);
	seg[id << 1 | 1][lazy[id] - 1][lazy[id] - 1] = e - mid - 1;
	lazy[id << 1 | 1] = lazy[id];
	S[mid] = S[e - 1] = char('a' + lazy[id] - 1);
	lazy[id] = 0;
}
 
void upd (int l, int r, int tmp, int s = 0, int e = n, int id = 1) {
	if (l <= s && e <= r) {
		memset(seg[id], 0, sizeof seg[id]);
		seg[id][tmp][tmp] = e - s - 1;
		lazy[id] = tmp + 1;
		S[s] = S[e - 1] = char('a' + tmp);
		return ;
	}
 
	if (r <= s || e <= l)
		return ;
 
	if (lazy[id])
		shift(s, e, id);
 
	int mid = e + s >> 1;
	upd(l, r, tmp, s, mid, id << 1);
	upd(l, r, tmp, mid, e, id << 1 | 1);
	merge(s, e, id);
}
 
int main() {
    fio;
	cin >> n >> m >> k >> S;
	build();
 
	while (m--) {
		int type;
		cin >> type;
 
		if (type == 1) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			l--;
 
			upd(l, r, c - 'a');
		}
		else {
			cin >> P;
			int res = 0;
			for (int i = 0; i < P.size(); i++)
				for (int j = i; j < P.size(); j++)
					res += seg[1][P[i] - 'a'][P[j] - 'a'];
 
			cout << 1 + res << endl;
		}
	}
}