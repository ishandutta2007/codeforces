
// Problem : E. Nastya and King-Shamans
// Contest : Codeforces - Codeforces Round #489 (Div. 2)
// URL : https://codeforces.com/problemset/problem/992/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
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
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 7;
const int infint = (ll)1e9;
const ll inf = (ll)2e13;
ll a[MAXN], n, lazy[4 * MAXN], q, seg[4 * MAXN];
 
void upd(ll node, ll x)
{
	seg[node] += x;
	lazy[node] += x;
	return;
}
 
void shift(ll node)
{
	upd(node * 2, lazy[node]);
	upd(node * 2 + 1, lazy[node]);
	lazy[node] = 0;
}
 
void inc(ll l, ll r, ll x, ll node = 1, ll st = 0, ll en = n)
{
	if(l >= en || st >= r) return ;
	if(l <= st && en <= r)
	{
		upd(node, x);
		return;
	}
	ll mid = (st + en) / 2;
	shift(node);
	inc(l, r, x, 2 * node, st, mid);
	inc(l, r, x, 2 * node + 1, mid, en);
	seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}
 
ll get(ll node = 1, ll st = 0, ll en = n)
{
	if(seg[node] < 0)
		return -1;
	if(en - st < 2)
	{
		if(seg[node] == 0)
			return st + 1;
		else
			return -1;
	}
	shift(node);
	ll mid = (st + en) / 2, t = 0;
	if((t = get(node * 2, st, mid)) != -1)
		return t;
	else
		return get(node * 2 + 1, mid, en);
}
 
int main()
{
	fio;
	cin>>n>>q;
	for (ll i = 0; i < n; i++)
	{
		cin>>a[i];
		inc(i, i + 1, a[i]);
		inc(i + 1, n, -a[i]);
	}
	for (ll i = 0; i < q; i++)
	{
		ll idx, val;
		cin>>idx>>val;
		idx--;
		ll tmp = val - a[idx];
		a[idx] = val;
		inc(idx, idx + 1, tmp);
		inc(idx + 1, n, -tmp);
		cout<<get()<<endl;
	}
}