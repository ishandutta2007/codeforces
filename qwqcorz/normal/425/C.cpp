#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int K=305;

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
vector<int>p[N];
int dp[N][K],nxt[N],a[N],b[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read(),s=read(),e=read(),k=s/e;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	for (int i=0;i<N;i++) nxt[i]=n+1;
	for (int j=1;j<=k;j++)
	{
		dp[0][j]=n+1;
		for (int i=0;i<=n+1;i++) p[i].clear();
		for (int i=1,mn=dp[0][j-1];i<=m;i++)
		{
			dp[i][j]=n+1;
			p[mn].push_back(i);
			mn=min(mn,dp[i][j-1]);
		}
		for (int i=0;i<=n;i++) nxt[a[i]]=n+1;
		for (int i=n;i>=0;i--)
		{
			for (int id:p[i]) dp[id][j]=nxt[b[id]];
			nxt[a[i]]=i;
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=k;j++)
	if (dp[i][j]<=n&&dp[i][j]+i+e*j<=s)
	ans=max(ans,j);
	print(ans);
	
	return 0;
}