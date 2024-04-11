
// Problem : E. k-d-sequence
// Contest : Codeforces - Codeforces Round #239 (Div. 1)
// URL : https://codeforces.com/problemset/problem/407/E
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
#define F first
#define S second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define pb push_back
#define ll long long
#define ld long double
#define int long long
//---------END-------//
 
const ll MAXN = 2e5 + 10, INF = 1e12 + 10;
ll a[MAXN], seg[4 * MAXN], lazy[4 * MAXN];
vector<pair<int, pii> > qmn, qmx;
map<int, int> mp;
 
void shift(int v){
	seg[2 * v] += lazy[v]; lazy[2 * v] += lazy[v];
	seg[2 * v + 1] += lazy[v]; lazy[2 * v + 1] += lazy[v];
	lazy[v] = 0;
}
 
int get(int v, int s, int e){
	if(seg[v] < 0) return INF;
	if(e - s < 2) return s;
	int mid = (s + e) / 2;
	shift(v);
	if(seg[2 * v] >= 0) return get(2 * v, s, mid);
	else return get(2 * v + 1, mid, e);
}
 
void upd(int v, int l, int r, int val, int s, int e){
	if(r <= s or e <= l)
		return;
	if(l <= s and e <= r){
		seg[v] += val;
		lazy[v] += val;
		return;
	}
	int mid = (s + e) / 2;
 	shift(v);
	upd(2 * v, l, r, val, s, mid);
	upd(2 * v + 1, l, r, val, mid, e);
	seg[v] = max(seg[2 * v], seg[2 * v + 1]);
	return;
}
 
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k, d, ans = 0, ansl = 0, ansr = 0;
	cin >> n >> k >> d;
	for(int i = 0; i < n; i ++)
		cin >> a[i], a[i] += 2e9;
	if(d == 0){
		for(int i = 0; i < n; i ++){
			int ptr = i;
			while(a[i] == a[ptr]) ptr ++;
			if(ptr - i > ans){
				ans = ptr - i;
				ansl = i;
				ansr = ptr - 1;
			} 
			i = ptr - 1;
		}
		cout << ansl + 1 << ' ' << ansr + 1 << endl;
		return 0;
	}
	upd(1, 0, n, -INF + k, 0, n);
	for(int i = 0; i < n; i ++){
		int ptr = i;
		while(ptr < n and a[ptr] % d == a[i] % d) ptr ++;
		for(int j = i; j < ptr; j ++){
			int l = mp[a[j]];
			mp[a[j]] = j + 1;
			a[j] = a[j] / d;
			upd(1, j, j + 1, +INF - 1, 0, n);
			upd(1, l, j + 1, +1, 0, n);
			upd(1, i, l, -INF, 0, n);
			int mnl = j, mxl = j;
			while(qmn.size()){
				int sz = qmn.size() - 1, val = qmn[sz].F, cl = qmn[sz].S.F, cr = qmn[sz].S.S;
				if(val <= a[j]) break;
				upd(1, cl, cr + 1, -val, 0, n);
				mnl = cl;
				qmn.pop_back();
			}
			while(qmx.size()){
				int sz = qmx.size() - 1, val = qmx[sz].F, cl = qmx[sz].S.F, cr = qmx[sz].S.S;
				if(val >= a[j]) break;
				upd(1, cl, cr + 1, +val, 0, n);
				mxl = cl;
				qmx.pop_back();
			}
			qmn.pb({a[j], {mnl, j}}); upd(1, mnl, j + 1, +a[j], 0, n);
			qmx.pb({a[j], {mxl, j}}); upd(1, mxl, j + 1, -a[j], 0, n);
		
			int id = get(1, 0, n);
			if(j - id + 1 > ans){
				ans = j - id + 1;
				ansl = id, ansr = j;
			}
		}
		qmx.clear(); qmn.clear(); upd(1, i, ptr, -INF, 0, n);
		i = ptr - 1;
	}
	cout << ansl + 1 << ' ' << ansr + 1 << endl;
}