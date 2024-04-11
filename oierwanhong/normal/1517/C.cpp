#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 511,INF=1e9+233;
int p[MAXN],a[MAXN][MAXN];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i)
	{
		int j=i,x=p[i], rest=x-1,r=i;
		a[i][i]=x;
		while(j>1&&rest&&!a[i][j-1])a[i][--j]=x,--rest;
		while(rest&&!a[r+1][j])
		{
			a[++r][j]=x,--rest;
			while(j>1&&rest&&!a[r][j-1])a[r][--j]=x,--rest;
		}
		if(rest)
		{
			a[-100][-1000]=5;
			return -5;
		}
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=i;++j)printf("%d ",a[i][j]);
	return 0;
}