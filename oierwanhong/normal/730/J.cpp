#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
typedef long long ll;
ll read()
{
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
bool umin(int& a,int t){if(a>t)return a=t,1;return 0;}
bool umax(int& a,int t){if(a<t)return a=t,1;return 0;}

#define MAXN 105
const int T=10000;
int g[MAXN][T<<1|1],f[MAXN][T<<1|1],a[MAXN],b[MAXN];
int main()
{
	memset(f,0x3f,sizeof f);
	const int INF=5e8;
	int n=read(),suma=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	f[0][T]=0;
	for(int i=1;i<=n;++i)
	{
		suma+=a[i];
		memcpy(g,f,sizeof f),memset(f,0x3f,sizeof f);
		for(int j=0;j<i;++j)
			for(int x=0;x<=(T<<1);++x)
			{
				if(x+a[i]<=(T<<1))umin(f[j][x+a[i]],g[j][x]);
				if(x-(b[i]-a[i])>=0)umin(f[j+1][x-(b[i]-a[i])],g[j][x]+b[i]-a[i]);
			}
	}
	for(int i=1;i<=n;++i)
	{
		int minv=1e9;
		for(int j=0;j<=T;++j)umin(minv,f[i][j]+j-T);
		if(minv<INF){printf("%d %d\n",i,minv);return 0;}
	}
	return 0;
}