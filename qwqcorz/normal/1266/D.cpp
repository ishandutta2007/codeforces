#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll siz[N];
map<int,ll>in[N],out[N];
void add(int u,int v,ll w)
{
	if (!(out[u][v]+=w)) out[u].erase(v);
	if (!(in[v][u]+=w)) in[v].erase(u);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		out[u][v]+=w;
		in[v][u]+=w;
		siz[u]+=w;
		siz[v]+=w;
	}
	vector<int>p;
	for (int i=1;i<=n;i++) p.push_back(i);
	sort(p.begin(),p.end(),[&](int x,int y){return siz[x]>siz[y];});
	for (int i:p)
	while (!in[i].empty()&&!out[i].empty())
	{
		int u=in[i].begin()->first,v=out[i].begin()->first;
		ll w=min(in[i].begin()->second,out[i].begin()->second);
		add(u,i,-w);
		add(i,v,-w);
		add(u,v,w);
	}
	int tot=0;
	for (int i=1;i<=n;i++) tot+=out[i].size();
	print(tot);
	for (int i=1;i<=n;i++)
	for (auto j:out[i])
	print(i,' '),print(j.first,' '),print(j.second);
	
	return 0;
}