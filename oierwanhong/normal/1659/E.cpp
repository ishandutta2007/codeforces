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
const int MAXN = 100011,LG = 30;
struct DSU
{
	int fa[MAXN],sum[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i,sum[i]=0;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y,int k)
	{
		x=find(x),y=find(y);
		if(x==y)return;
		fa[x]=y,sum[y]+=sum[x]+k;
	}
	int Qsum(int x){return sum[find(x)];}
	bool same(int x,int y){return find(x)==find(y);}
}S[LG],F[LG];
bool win[MAXN];
int main()
{
	int n=read(),m=read();
	for(int k=0;k<LG;++k)S[k].init(n),F[k].init(n);
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),w=read();
		for(int k=0;k<LG;++k)
			if(w&(1<<k))S[k].uni(x,y,0);
		bool c=w&1;
		if(c)
		{
			F[0].uni(x,y,0);
			//printf("S[0] uni %d %d with 0\n",x,y);
			for(int k=1;k<LG;++k)
				if(w&(1<<k))F[k].uni(x,y,0);//,printf("S[%d] uni %d %d with 0\n",k,x,y);
		}
		else
		{
			for(int k=1;k<LG;++k)
				F[k].uni(x,y,1);//,printf("S[%d] uni %d %d with 1\n",k,x,y);
		}
	}
	for(int u=1;u<=n;++u)
		for(int k=1;k<LG;++k)
			if(F[k].Qsum(u))win[u]=1;
	int q=read();
	while(q--)
	{
		int x=read(),y=read();
		bool flag=0;
		for(int k=0;k<LG&&!flag;++k)
			if(S[k].same(x,y)){flag=1;break;}
		if(flag){puts("0");continue;}
		if(win[x])puts("1");
		else puts("2");
	}
	return 0;
}