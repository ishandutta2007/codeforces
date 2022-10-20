#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool is[N];
int u[N],v[N],deep[N],c[N],fa[N];
vector<int>e[N],t[N];
void dfs0(int now,int father)
{
	deep[now]=deep[father]+1;
	for (int to:e[now])
	{
		if (to==father||deep[to]) continue;
		dfs0(to,now);
		t[now].push_back(to);
		fa[to]=now;
//		print(now,','),print(to);
	}
}
vector<pair<int,int>>a;
void dfs1(int now){for (int to:t[now]) dfs1(to),c[now]+=c[to];}
void dfs2(int now,int d)
{
	for (int to:e[now]) if (deep[to]<d&&deep[now]-deep[to]>1) a.push_back(make_pair(now,to));
	for (int to:t[now]) dfs2(to,d);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		::u[i]=u,::v[i]=v;
	}
	for (int i=1;i<=n;i++) if (!deep[i]) dfs0(i,0),is[i]=1;
	for (int i=1;i<=m;i++)
	if (abs(deep[u[i]]-deep[v[i]])!=1)
	{
		if (deep[u[i]]>deep[v[i]]) swap(u[i],v[i]);
		c[u[i]]--,c[v[i]]++;
	}
	for (int i=1;i<=n;i++) if (is[i]) dfs1(i);
	int rt=0;
	for (int i=1;i<=n;i++) if (c[i]>=2) rt=i;
	if (!rt) return puts("NO"),0;
//	print(rt);
	dfs2(rt,deep[rt]);
	assert(a.size()>=2);
	memset(c,0,sizeof(c));
	int u=a[0].first,v=a[0].second;
	int x=a[1].first,y=a[1].second;
//	print(u,' '),print(v);
//	print(x,' '),print(y);
	memset(c,0,sizeof(c));
	vector<int>A,B;
	int now=u;
	while (1)
	{
		c[now]++;
		A.push_back(now);
		if (now==v) break;
		now=fa[now];
	}
	now=x;
	while (1)
	{
		c[now]++;
		B.push_back(now);
		if (now==y) break;
		now=fa[now];
	}
	vector<int>X,Y,Z;
	u=v=-1;
	for (int i=0;i<(int)A.size();i++)
	if (c[A[i]]==2)
	{
		X.push_back(A[i]);
		if (!~u) u=i;
		v=i;
	}
	for (int i=u;i>=0;i--) Y.push_back(A[i]);
	for (int i=(int)A.size()-1;i>=v;i--) Y.push_back(A[i]);
	u=v=-1;
	for (int i=0;i<(int)B.size();i++)
	if (c[B[i]]==2)
	{
		if (!~u) u=i;
		v=i;
	}
	for (int i=u;i>=0;i--) Z.push_back(B[i]);
	for (int i=(int)B.size()-1;i>=v;i--) Z.push_back(B[i]);
	puts("YES");
	print(X.size(),' ');for (int i:X) print(i,' ');puts("");
	print(Y.size(),' ');for (int i:Y) print(i,' ');puts("");
	print(Z.size(),' ');for (int i:Z) print(i,' ');puts("");
	
	return 0;
}