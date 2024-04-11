
// Problem : B. Aroma's Search
// Contest : Codeforces - Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/B
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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j,xs,ys,ax,ay,bx,by;
vector<pll> lis;
ll dist (ll x1, ll y1, ll x2, ll y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
ll enc (ll a, ll b)
{
	
	if (a==1e9) return dist(xs,ys,lis[b].fi,lis[b].se);
	else{ 
	if ((a<0)or(a>=n)or(b<0)or(b>=n))
	{
		cout<<a<<' '<<b<<' '<<"invalid"<<endl;
	}
	else
	return  dist(lis[a].fi,lis[a].se,lis[b].fi,lis[b].se);
	}
}
int main()
{
//  ofile;
    fio;
    cin>>xs>>ys;
    lis.push_back({xs,ys});
    cin>>ax>>ay>>bx>>by;
    while(true)
    {
    	xs=lis[lis.size()-1].fi*ax+bx;
    	ys=lis[lis.size()-1].se*ay+by;
    	if ((xs>2e16)or(ys>2e16)) break;
    	else lis.push_back({xs,ys});
    }
    n=lis.size();
    cin>>xs>>ys>>t;
    for (i=0;i<n;i++)
    for (j=0;j<=i;j++)
    for (k=j;k<n;k++)
    {
 //   	cout<<i<<' '<<j<<' '<<k<<endl;
    	if (enc(1e9,i)+enc(i,j)+enc(j,k)<=t) t1=max(t1,max(max(i,j),k)-min(min(i,j),k)+1);
    }
    cout<<t1;
}