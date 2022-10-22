#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 1000011;
int n;
int a[MAXN];
std::vector<int>g[MAXN];
struct one
{
	int l,k,dex;
};
std::vector<one>Q[MAXN];
std::set<int>s[MAXN];
struct BIT
{
	int t[MAXN];
#define lowb (i&-i)
	void modify(int i,int k)
	{
		while(i<=n)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
	int Qkth(int k)
	{
		int num=0;
		for(int i=20;i>=0;--i)
			if(num+(1<<i)<=n&&k>t[num+(1<<i)])num+=1<<i,k-=t[num];
		return num+1;
	}
}bt;
int cnt[MAXN],res[MAXN];
void dfs(int u)
{
	int x=a[u];
	if(cnt[x])s[cnt[x]].erase(x),bt.modify(cnt[x],-1);
	++cnt[x],s[cnt[x]].insert(x),bt.modify(cnt[x],1);
	for(auto P:Q[u])
	{
		int k=bt.Qsum(P.l)+P.k;
		int pos=bt.Qkth(k);
		if(pos>n)res[P.dex]=-1;
		else res[P.dex]=*s[pos].begin();
	}
	for(auto v:g[u])dfs(v);
	s[cnt[x]].erase(x),bt.modify(cnt[x],-1),--cnt[x];
	if(cnt[x])s[cnt[x]].insert(x),bt.modify(cnt[x],1);
}
int main()
{
	int task=read();
	while(task--)
	{
		n=read();
		int m=read();
		for(int i=1;i<=n;++i)g[i].clear(),Q[i].clear();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=2;i<=n;++i)g[read()].emplace_back(i);
		for(int i=1;i<=m;++i)
		{
			int u=read(),l=read()-1,k=read();
			Q[u].emplace_back(one{l,k,i});
		}
		dfs(1);
		for(int i=1;i<=m;++i)printf("%d ",res[i]);
		puts("");
	}
	return 0;
}