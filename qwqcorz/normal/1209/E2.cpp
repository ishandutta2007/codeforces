#include<bits/stdc++.h>
using namespace std;
const int N=15;
const int M=2e3+5;
const int Max=(1<<13)-1;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool f[M];
int a[N][M],b[M],c[M],v[N][N],g[N][Max+5],dp[N][Max+5],n,m;
vector<int>st[Max+5];
bool cmp(int x,int y)
{
	return b[x]>b[y];
}
void dfs(int i,int j,int now,int sum)
{
	if (j>n) return void(g[i][now]=max(g[i][now],sum));
	dfs(i,j+1,now,sum);
	dfs(i,j+1,now|(1<<(j-1)),sum+v[j][i]);
}

int main()
{
	for (int i=0;i<=Max;i++) st[i].clear();
	for (int i=0;i<=Max;i++)
	for (int j=0;j<=Max;j++)
	if ((i|j)==i) st[i].push_back(j);
	int T=read();
	while (T--)
	{
		n=read();
		m=read();
		for (int i=1;i<=m;i++) b[i]=f[i]=0;
		for (int i=1;i<=m;i++) c[i]=i;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) b[j]=max(b[j],a[i][j]=read());
		sort(c+1,c+1+m,cmp);
		for (int i=1;i<=n;i++) f[c[i]]=1;
		int cnt=0;
		for (int i=1;i<=m;i++)
		if (f[i])
		{
			cnt++;
			for (int j=1;j<=n;j++) v[j][cnt]=a[j][i];
		}
		int num=(1<<n)-1;
		for (int i=0;i<=cnt;i++)
		for (int j=0;j<=num;j++) g[i][j]=0;
		for (int i=1;i<=cnt;i++)
		for (int j=1;j<=n;j++)
		{
			dfs(i,1,0,0);
			v[0][i]=v[n][i];
			for (int k=n-1;k>=1;k--) v[k+1][i]=v[k][i];
			v[1][i]=v[0][i];
//			for (int k=1;k<=n;k++) print(v[k][i],' ');puts("");
		}
//		for (int i=1;i<=cnt;i++)
//		for (int j=0;j<=num;j++) print(i,' '),print(j,':'),print(g[i][j]);
		for (int i=0;i<=cnt;i++)
		for (int j=0;j<=num;j++) dp[i][j]=0;
		for (int i=1;i<=cnt;i++)
		for (int j=0;j<=num;j++)
		for (int k=0;k<st[j].size();k++)
		dp[i][j]=max(dp[i][j],dp[i-1][st[j][k]]+g[i][j^st[j][k]]);
		print(dp[cnt][num]);
	}

	return 0;
}