#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m,Q,tot=0;
set<pair<int,int>>S,ans;
bitset<N>a[N],pre[N];
void init()
{
	pre[0].set(0);
	for (int i=1;i<=m;i++) pre[i]=pre[i-1],pre[i].set(i);
	for (int i=1;i<=n;i++) S.insert({0,i});
}
void del(int x)
{
	int siz=a[x].count();
	auto now=S.find({-siz,x});
	if (now!=S.begin())
	{
		auto tmp=prev(now);
		int u=tmp->second,v=now->second;
		if ((~a[u]&a[v]).any()) ans.erase({u,v});
	}
	if (next(now)!=S.end())
	{
		auto tmp=next(now);
		int u=now->second,v=tmp->second;
		if ((~a[u]&a[v]).any()) ans.erase({u,v});
	}
	if (now!=S.begin()&&next(now)!=S.end())
	{
		auto tmp1=prev(now);
		auto tmp2=next(now);
		int u=tmp1->second,v=tmp2->second;
		if ((~a[u]&a[v]).any()) ans.insert({u,v});
	}
	S.erase(now);
}
void ins(int x)
{
	int siz=a[x].count();
	auto now=S.insert({-siz,x}).first;
	if (now!=S.begin())
	{
		auto tmp=prev(now);
		int u=tmp->second,v=now->second;
		if ((~a[u]&a[v]).any()) ans.insert({u,v});
	}
	if (next(now)!=S.end())
	{
		auto tmp=next(now);
		int u=now->second,v=tmp->second;
		if ((~a[u]&a[v]).any()) ans.insert({u,v});
	}
	if (now!=S.begin()&&next(now)!=S.end())
	{
		auto tmp1=prev(now);
		auto tmp2=next(now);
		int u=tmp1->second,v=tmp2->second;
		if ((~a[u]&a[v]).any()) ans.erase({u,v});
	}
}

signed main()
{
	n=read(),m=read(),Q=read();
	init();
	while (Q--)
	{
		int x=read(),l=read(),r=read();
		del(x);
		a[x]^=pre[r]^pre[l-1];
		ins(x);
		if (!ans.empty())
		{
			auto [x,y]=*ans.begin();
			auto A=a[x]&~a[y],B=~a[x]&a[y];
			int u=A._Find_first(),v=B._Find_first();
			if (x>y) swap(x,y);
			if (u>v) swap(u,v);
			print(x,' '),print(u,' ');
			print(y,' '),print(v);
		}
		else puts("-1");
	}
	
	return 0;
}