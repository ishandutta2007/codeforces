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
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
 
#define maxn 100110
double dp[maxn][110];
int a[maxn];
double res;
double tt[110];
int mx[maxn];
void copy(int t)
{
	for(int i=0;i<=100;++i)
		dp[t][i]=tt[i];
}
double c(double n,double m)
{
	double ret=1;
	while(m>=1.0)
	{
		ret*=n/m;
		n-=1.0; m-=1.0;
	}
	return ret;
}
void take(int u,int g,int w)
{
	for(int i=0;i<=min(g,w);++i)
	{
		double tmp=dp[u][g]*c(g,i)*c(a[u]-g,w-i)/c(a[u],w);
		tt[g-i]+=tmp;
	}
}
 
void solve()
{
	int u,v,w;
	cin>>u>>v>>w;
	memset(tt,0,sizeof(tt));
	res-=dp[u][0];
	for(int i=0;i<=100;++i)
		if(dp[u][i]>1e-12) take(u,i,w);
	copy(u); a[u]-=w; a[v]+=w;
	res+=dp[u][0];
	cout<<fixed<<setprecision(10)<<res<<endl;
}
		
 
int main()
{
    fio;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i) dp[i][a[i]]=1.0;
	res=0.0;
	for(int i=1;i<=n;++i)
		if(!a[i]) res++;
	int q;
	cin>>q;
	while(q--) solve();
}