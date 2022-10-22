#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011;
struct DSU
{
	int fa[MAXN],size[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return 0;
		fa[x]=y,size[y]+=size[x];
		return 1;
	}
}dsu;
int main()
{
	int n=read(),m=read(),ex=0;
	dsu.init(n);
	while(m--)
	{
		int x=read(),y=read();
		ex+=!dsu.uni(x,y);
		std::vector<int>a;
		for(int i=1;i<=n;++i)
			if(dsu.find(i)==i)a.emplace_back(dsu.size[i]);
		std::sort(a.begin(),a.end()),std::reverse(a.begin(),a.end());
		int ans=0;
		for(int i=0;i<=ex&&i<a.size();++i)ans+=a[i];
		printf("%d\n",ans-1);
	}
	return 0;
}