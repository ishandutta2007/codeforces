#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=16;
const int S=1<<16;
const int M=2005;

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
bitset<M>dp[S];
int a[N],d[N],n,k,s,m=0;
priority_queue<pair<int,int>>q;
void dfs(int x,int y)
{
	if (!x) return;
	for (;y*k<M&&dp[x][y*k];y*=k)
	for (int i=0;i<n;i++)
	if ((x>>i)&1) d[i]++;
	for (int i=0;i<n;i++)
	if (((x>>i)&1)&&y>=a[i]&&dp[x^(1<<i)][y-a[i]])
	return dfs(x^(1<<i),y-a[i]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),k=read(),s=(1<<n)-1;
	for (int i=0;i<n;i++) m+=a[i]=read();
	for (int i=dp[0][0]=1;i<=s;i++)
	{
		for (int j=0;j<n;j++) if ((s>>j)&1) dp[i]|=dp[i^(1<<j)]<<a[j];
		for (int j=m/k;j>=1;j--) if (dp[i][j*k]) dp[i][j]=1;
	}
	if (!dp[s][1]) puts("NO");
	else
	{
		puts("YES");
		dfs(s,1);
		for (int i=0;i<n;i++) q.push(mk(d[i],a[i]));
		while ((int)q.size()>1)
		{
			auto x=q.top(); q.pop();
			auto y=q.top(); q.pop();
			print(x.se,' '),print(y.se);
			x.se+=y.se;
			while (x.se%k==0) x.se/=k,x.fi--;
			q.push(x);
		}
	}
	
	return 0;
}