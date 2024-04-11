#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 4011;
int a[MAXN][MAXN],b[MAXN][MAXN];
int res[MAXN][MAXN];
pii pa[2011*2011],pb[2011*2011];
int main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			a[i][j]=read(),b[i-j+n][i+j-1]=a[i][j];
			pa[a[i][j]]=pii(i,j);
			pb[a[i][j]]=pii(i-j+n,i+j-1);
		}
	int sx=1,tx=n+n,sy=1,ty=n+n;
	for(int v=n*n;v;--v)
	{
		int x=pb[v].first,y=pb[v].second;
		if(sx<=x&&x<=tx&&sy<=y&&y<=ty)
		{
			res[pa[v].first][pa[v].second]=1;
			umax(sx,x-k),umin(tx,x+k);
			umax(sy,y-k),umin(ty,y+k);
		}
		else res[pa[v].first][pa[v].second]=0;
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)putchar(res[i][j]?'M':'G');
	return 0;
}