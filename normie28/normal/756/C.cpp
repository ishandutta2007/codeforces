
// Problem : C. Nikita and stack
// Contest : Codeforces - 8VC Venture Cup 2017 - Final Round
// URL : https://codeforces.com/problemset/problem/756/C
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
const int N(111111);
int mx[N * 4], sum[N * 4], a[N];
int inf(1e9);
void pushdown(int k) {
	sum[k * 2] += sum[k];
	mx[k * 2] += sum[k];
	sum[1 + k * 2] += sum[k];
	mx[1 + k * 2] += sum[k];
	sum[k] = 0;
}
void modify(int k, int le, int ri, int ql, int qr, int delta) {
	if(ql <= le && ri <= qr) {
		sum[k] += delta;
		mx[k] += delta;
	}else {
		pushdown(k);
		int mid(le + ri >> 1);
		if(ql <= mid)
			modify(k * 2, le, mid, ql, qr, delta);
		if(qr >= mid + 1)
			modify(k * 2 + 1, mid + 1, ri, ql, qr, delta);
		mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
	}
}
void activate(int k, int le, int ri, int x) {
	if(le == ri) {
		mx[k] = sum[k];
	}else {
		pushdown(k);
		int mid(le + ri >> 1);
		if(x <= mid)
			activate(k * 2, le, mid, x);
		else
			activate(k * 2 + 1, mid + 1, ri, x);
		mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
	}
}
int find(int k, int le, int ri) {
	if(mx[k] < 0)
		return -1;
	if(le == ri) {
		return a[le];
	}else {
		int mid(le + ri >> 1);
		pushdown(k);
		if(mx[k * 2 + 1] >= 0) {
			return find(k * 2 + 1, mid + 1, ri);
		}else {
			return find(k * 2, le, mid);
		}
	}
}
int main() {
	fio;
	cin>>n;
	fill(mx + 1, mx + 4 * n + 1, -inf);
	for(int i(1); i <= n; i++) {
		int t, tp;
		cin >> t >> tp;
		if(tp == 1) {
			int x;
			cin >> x;
			a[t] = x;
			if(t > 1) 
				modify(1, 1, n, 1, t - 1, +1);
			activate(1, 1, n, t);
		}else {
			if(t > 1)
				modify(1, 1, n, 1, t - 1, -1);
		}
		cout << find(1, 1, n) << endl;
	}
 
}