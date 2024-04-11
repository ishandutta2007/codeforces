#include<bits/stdc++.h>
using namespace std;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int cnt=1,m=0;
vector<pair<int,int>>e[55];
void add_edge(int u,int v,int w){m++,e[u].push_back(make_pair(32-v,w));}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int L=read(),R=read(),n=R-L+1,k=(int)log2(n);
	puts("YES");
	for (int i=1;i<=k+1;i++)
	{
		add_edge(32-i,0,1<<(i-1));
		for (int j=1;j<i;j++) add_edge(32-i,j,1<<(i-1));
	}
	add_edge(1,0,L);
	for (int i=1;i<=k;i++) add_edge(1,i,L);
	int sum=1<<k,tmp=k+2,tmp0=k+3;
	add_edge(1,tmp,L);
	add_edge(1,tmp0,L);
	for (int i=k-1;i>=0;i--)
	if ((n>>i)&1)
	{
		add_edge(32-tmp,i+1,sum-(1<<i));
		sum+=1<<i;
	}
	print(32,' '),print(m);
	for (int i=1;i<=32;i++)
	for (auto j:e[i]) print(i,' '),print(j.first,' '),print(j.second);
	
	return 0;
}