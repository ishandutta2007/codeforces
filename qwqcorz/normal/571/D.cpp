#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct dsu
{
	vector<int>a[N],b[N];
	vector<ll>sum[N];
	int fa[N],siz[N],tag[N],n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return x==fa[x]?x:find(fa[x]);}
	void merge(int x,int y,int t)
	{
		x=find(x),y=find(y);
		if (x==y) return;
		if (siz[x]>siz[y]) swap(x,y);
		tag[x]=t,fa[x]=y;
		siz[y]+=siz[x];
	}
	void modify(int x,int t)
	{
		x=find(x);
		a[x].push_back(t);
		b[x].push_back(siz[x]);
		sum[x].push_back((sum[x].empty()?0:sum[x].back())+siz[x]);
	}
	ll calc(int x,int l){return sum[x].back()-(l?sum[x][l-1]:0);}
	int gettime(int x)
	{
		int ret=0,lst=0;
		while (1)
		{
			if (!a[x].empty()&&a[x].back()>lst) ret=max(ret,a[x].back());
			if (x==fa[x]) return ret;
			lst=tag[x];
			x=fa[x];
		}
	}
	ll solve(int x,int t)
	{
		ll ret=0;
		int lst=0;
		while (1)
		{
			auto tmp=lower_bound(a[x].begin(),a[x].end(),max(lst,t));
			if (tmp!=a[x].end()) ret+=calc(x,tmp-a[x].begin());
			if (x==fa[x]) return ret;
			lst=tag[x];
			x=fa[x];
		}
	}
}s,c;

signed main()
{
	int n=read(),m=read();
	s.send(n),c.send(n);
	for (int i=1;i<=m;i++)
	{
		char opt=getchar();
		while (opt<'A'||'Z'<opt) opt=getchar();
		int x=read(),y=opt=='U'||opt=='M'?read():0;
		if (opt=='U') s.merge(x,y,i);
		if (opt=='M') c.merge(x,y,i);
		if (opt=='A') s.modify(x,i);
		if (opt=='Z') c.modify(x,i);
		if (opt=='Q')
		{
			int t=c.gettime(x);
			print(s.solve(x,t));
		}
	} 
	
	return 0;
}