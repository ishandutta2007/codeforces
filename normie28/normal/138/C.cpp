
// Problem : C. Mushroom Gnomes - 2
// Contest : Codeforces - Codeforces Beta Round #99 (Div. 1)
// URL : https://codeforces.com/problemset/problem/138/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
struct mush
{
	ll a,h,l,r;
};
mush arr[100005];
struct mu
{
	ll x,v;
};
bool operator < (mu m1, mu m2)
{
	if(m1.x != m2.x)return m1.x < m2.x;
	return m1.v < m2.v;
}
mu mus[10005];
double pr[50005];
double query(int ind, int nd=1, int l=0, int r=10005)
{
	if(l==r)return pr[nd];
	int m=(l+r)>>1;
	double ans=pr[nd];
	if(ind <=m )
	{
		ans*=query(ind, nd<<1, l, m);
	}
	else
	{
		ans*=query(ind, (nd<<1) + 1, m+1, r);
	}
	return ans;
}
void upd(int a, int b, double val, int nd=1, int l=0, int r=10005)
{
	if(a==l && b==r)
	{
		pr[nd]*=val;
		return ;
	}
	int m = (l+r)>>1;
	if(a<=m)
		upd(a, min(m, b), val, nd<<1, l, m);
	if(b>m)
		upd(max(a, m+1), b, val, (nd<<1)+1, m+1, r);
}
int main()
{
	fio;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>arr[i].a>>arr[i].h>>arr[i].l>>arr[i].r;
	for(int i=0;i<m;++i)
	{
		cin>>mus[i].x>>mus[i].v;
	}
	sort(mus, mus+m);
	for(int i=0;i<50005;++i)pr[i]=1;
	for(int i=0;i<n;++i)
	{
		mush now=arr[i];
		mu ts = {arr[i].a, 10000};
		int ind1 = lower_bound(mus, mus+m, ts) - mus;
		ts.x=arr[i].a + arr[i].h;
		int ind2 = lower_bound(mus, mus+m, ts) - mus;
		ind2--;
		if(ind1 <=ind2 && arr[i].r !=0)
		{
			upd(ind1, ind2, (double)(100-arr[i].r) * 0.01);
		}
		ts.x = arr[i].a - arr[i].h - 1;
		ind1 = lower_bound(mus, mus+m, ts) - mus;
		ts.x = arr[i].a-1;
		ind2 = lower_bound(mus, mus+m, ts) - mus;
		ind2--;
		if(ind1 <= ind2 && arr[i].l !=0)
		{
			upd(ind1, ind2, (double)(100-arr[i].l)*0.01);
		}
	}
	double ans=0;
	for(int i=0;i<m;++i)
	{
		ans+=query(i)*mus[i].v;
	}
	cout<<fixed<<setprecision(9)<<ans;
}