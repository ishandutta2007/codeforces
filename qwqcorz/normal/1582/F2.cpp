#include<bits/stdc++.h>
using namespace std;
const int M=1<<13;

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
int dis[M];
vector<int>q[M];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (int i=1;i<M;i++) dis[i]=M;
	for (int i=1;i<M;i++) q[i].push_back(0);
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		for (int u:q[x])
		{
			int to=u^x;
			while (dis[to]>x) if (--dis[to]>x) q[dis[to]].push_back(to);
		}
		q[x].clear();
	}
	vector<int>ans;
	for (int i=0;i<M;i++) if (dis[i]<M) ans.push_back(i);
	print(ans.size());
	for (int i:ans) print(i,' ');
	
	return 0;
}