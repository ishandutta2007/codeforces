// Problem : F. Sonya and Bitwise OR
// Contest : Codeforces - Codeforces Round #495 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1004/F
// Memory Limit : 512 MB
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
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define INF (1ll<<58)
#define tree treee
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
typedef std::pair<ll,ll> pll;
typedef std::string str;
//---------END-------//
 
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
#define MAXN 505
ll a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN],f[MAXN/2][MAXN][MAXN];
ll s(ll sum[][MAXN],ll x1,ll y1,ll x2,ll y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	fio;
	ll n,m,task;
	cin>>n>>m>>task;
	for(ll i=1;i<=n;++i)
	{
		char cur;
		for(ll j=1;j<=m;++j)
		{
			cin>>cur;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(cur=='R');
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(cur=='G');
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(cur=='Y');
			d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(cur=='B');
		}
	}
	for(ll k=1;k<=250;++k)
		for(ll i=k<<1;i<=n;++i)
			for(ll j=k<<1;j<=m;++j)
			{
				f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
				ll sa=s(a,i-k-k+1,j-k-k+1,i-k,j-k),sb=s(b,i-k-k+1,j-k+1,i-k,j),sc=s(c,i-k+1,j-k-k+1,i,j-k),sd=s(d,i-k+1,j-k+1,i,j);
				if(sa==k*k && sb==k*k && sc==k*k && sd==k*k)++f[k][i][j];
			}
	while(task--)
	{
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll l=0,r=min((x2-x1+1)/2,(y2-y1+1)/2);
		while(l<r)
		{
			ll mid=(l+r+1)>>1,tmp=s(f[mid],x1+mid+mid-1,y1+mid+mid-1,x2,y2);
			if(tmp>0)l=mid;
			else r=mid-1;
		}
		cout<<l*l*4<<endl;
	}
}