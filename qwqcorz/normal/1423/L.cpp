#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=35;

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
vector<pair<bitset<N>,int>>a;
unordered_map<bitset<N>,int>mp;
bitset<N>l[M],now;
void dfs1(int i,int n,int tot)
{
	if (i>n) return void(a.push_back(make_pair(now,tot)));
	dfs1(i+1,n,tot);
	now^=l[i];
	dfs1(i+1,n,tot+1);
	now^=l[i];
}
void dfs2(int i,int n,int tot)
{
	if (i>n) return void(mp.count(now)?mp[now]=min(mp[now],tot):mp[now]=tot);
	dfs2(i+1,n,tot);
	now^=l[i];
	dfs2(i+1,n,tot+1);
	now^=l[i];
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		int tot=read();
		for (int j=1;j<=tot;j++) l[i][read()]=1;
	}
	dfs1(1,min(m,10),0);
	dfs2(11,m,0);
	for (int i=1;i<=q;i++)
	{
		now.reset();
		int tot=read(),ans=114514;
		for (int j=1;j<=tot;j++) now[read()]=1;
		for (auto j:a)
		{
			auto tmp=j.first^now;
			if (mp.count(tmp)) ans=min(ans,j.second+mp[tmp]);
		}
		print(ans<=m?ans:-1);
	}
	
	return 0;
}