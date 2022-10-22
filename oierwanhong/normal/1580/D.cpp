#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 4011;
const ll INF = 1.233e18;
int ls[MAXN],rs[MAXN];
int a[MAXN],s[MAXN],n,m;
int size[MAXN];
ll f[MAXN][MAXN],tp[MAXN];
void dfs(int u)
{
	size[u]=1;
	if(ls[u])dfs(ls[u]),size[u]+=size[ls[u]];
	if(rs[u])dfs(rs[u]),size[u]+=size[rs[u]];
	for(int x=0;x<=size[u];++x)tp[x]=-INF;
	tp[0]=0;
	for(int x=0;x<=size[ls[u]];++x)
		for(int y=0;y<=size[rs[u]];++y)umax(tp[x+y],f[ls[u]][x]+f[rs[u]][y]-2ll*a[u]*x*y);
	for(int x=0;x<=size[u];++x)
	{
		f[u][x]=tp[x];
		if(x)umax(f[u][x],tp[x-1]+ll(m)*a[u]-ll(2*x-1)*a[u]);
	}
}
int main()
{
	n=read(),m=read();
	int top=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		while(top&&a[s[top]]>a[i])ls[i]=s[top],--top;
		rs[s[top]]=i,s[++top]=i;
	}
	dfs(s[1]);
	printf("%lld\n",f[s[1]][m]);
	return 0;
}