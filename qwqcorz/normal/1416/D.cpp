#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N],u[N],v[N];
bool del[N];
struct cmp
{
	bool operator ()(const int &x,const int &y)
	{
		return p[x]>p[y];
	}
};
struct Query
{
	int opt,x;
}q[N];
int id[N];
vector<int>t[N];
int fa[N],siz[N];
set<int,cmp>d[N];
int find(int x){return fa[x]==x?x:find(fa[x]);}
void merge(int x,int y,int i)
{
	x=find(x),y=find(y);
	if (x==y) return;
	if (siz[x]>siz[y]) swap(x,y);
	if (i)
	{
		id[i]=x;
		for (int j:d[x]) t[i].push_back(j);
	}
	fa[x]=y;
	siz[y]+=siz[x];
	for (int j:d[x]) d[y].insert(j);
	d[x].clear();
}

signed main()
{
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	for (int i=1;i<=Q;i++)
	{
		q[i].opt=read();
		q[i].x=read();
		if (q[i].opt==2) del[q[i].x]=1;
	}
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,d[i].insert(i);
	for (int i=1;i<=m;i++) if (!del[i]) merge(u[i],v[i],0);
	for (int i=Q;i>=1;i--)
	if (q[i].opt==1) id[i]=find(q[i].x);
				else merge(u[q[i].x],v[q[i].x],i);
	for (int i=1;i<=Q;i++)
	if (q[i].opt==1)
	{
		int x=id[i];
		if (d[x].empty()) puts("0");
		else
		{
			print(p[*d[x].begin()]);
			p[*d[x].begin()]=0;
			d[x].erase(d[x].begin());
		}
	}
	else
	{
		int x=id[i];
		if (!x) continue;
		for (int j:t[i])
		if (p[j])
			d[x].insert(j),
			d[fa[x]].erase(j);
	}
	
	return 0;
}