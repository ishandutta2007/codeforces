#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int ans=0;
set<int>e[N];
void add(int u,int v)
{
	if (!e[u].empty()) ans-=u<*e[u].rbegin();
	if (!e[v].empty()) ans-=v<*e[v].rbegin();
	e[u].insert(v);
	e[v].insert(u);
	ans+=u<*e[u].rbegin();
	ans+=v<*e[v].rbegin();
}
void del(int u,int v)
{
	ans-=u<*e[u].rbegin();
	ans-=v<*e[v].rbegin();
	e[u].erase(v);
	e[v].erase(u);
	if (!e[u].empty()) ans+=u<*e[u].rbegin();
	if (!e[v].empty()) ans+=v<*e[v].rbegin();
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	int q=read();
	for (int i=1;i<=q;i++)
	{
		int opt=read(),u=opt<=2?read():0,v=opt<=2?read():0;
		if (opt==1) add(u,v);
		if (opt==2) del(u,v);
		if (opt==3) print(n-ans);
	}
	
	return 0;
}