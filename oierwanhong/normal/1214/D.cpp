//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1000011
bool ok[MAXN];char a[MAXN];
ll n,m;
ll num(ll x,ll y){return (x-1)*m+y;}
bool dfs(ll x,ll y)
{
	if(x==n&&y==m)return 1;
	if(!ok[num(x,y)])return 0;
	ok[num(x,y)]=0;
	if(x<n&&dfs(x+1,y))return 1;
	if(y<m&&dfs(x,y+1))return 1;
	return 0;
}
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;++i)
	{
		scanf("%s",a+1);
		for(ll j=1;j<=m;++j)ok[num(i,j)]=(a[j]=='.') ;
	}
	ll ans=dfs(1,1);
	ok[1]=1;std::cout<<ans+dfs(1,1);
}