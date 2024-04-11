#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<bitset>
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

const int MAXN = 1000011;
namespace DSU
{
	int fa[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y)
	{
		x=find(x),y=find(y);
		fa[x]=y;
	}
}
bool vis[MAXN];
int pri[MAXN],minp[MAXN],pcnt;
void sieve()
{
	vis[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(!vis[i])pri[++pcnt]=i,minp[i]=pcnt;
		for(int j=1;j<=pcnt&&i*pri[j]<MAXN;++j)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){minp[i*pri[j]]=j;break;}
			minp[i*pri[j]]=j;
		}
	}
}
std::set<pii>st;
int a[MAXN];
int main()
{
	sieve();
	int n=read(),m=read();
	DSU::init(n+pcnt);
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		int x=a[i];
		while(x>1)
		{
			int p=minp[x];
			DSU::uni(i,n+p);
			while(x%pri[p]==0)x/=pri[p];
		}
	}
	for(int i=1;i<=n;++i)
	{
		std::vector<int>seq;
		seq.push_back(DSU::find(i));
		int x=a[i]+1;
		while(x>1)
		{
			int p=minp[x],rt=DSU::find(n+p);
			for(auto v:seq)
			{
				st.insert(pii(rt,v));
			}
			seq.push_back(rt);
			while(x%pri[p]==0)x/=pri[p];
		}
	}
	while(m--)
	{
		int s=read(),t=read();
		if(DSU::find(s)==DSU::find(t)){puts("0");}
		else if(st.count(pii(DSU::find(s),DSU::find(t)))||st.count(pii(DSU::find(t),DSU::find(s)))){puts("1");}
		else puts("2");
	}
	return 0;
}