#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int K=8;

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
inline void up(int &x,int y){if (x<y) x=y;}
int dp[N][1<<K],to[1<<K],b[N],l[N],r[N],popcount[1<<K];
vector<int>a[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	for (int i=1;i<256;i++) popcount[i]=!popcount[i&(i-1)];
	int n=read(),m=read(),k=read(),cnt=0;
	for (int i=1;i<=n;i++)
		b[++cnt]=l[i]=read(),
		b[++cnt]=r[i]=read()+1;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) l[i]=lower_bound(b+1,b+1+cnt,l[i])-b;
	for (int i=1;i<=n;i++) r[i]=lower_bound(b+1,b+1+cnt,r[i])-b;
	b[cnt+1]=m+1;
	for (int i=1;i<=cnt;i++) b[i]=b[i+1]-b[i];
	for (int i=1;i<=n;i++)
	for (int j=l[i];j<r[i];j++) a[j].push_back(i);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=cnt;i++)
	{
		int m=a[i-1].size(),n=a[i].size();
		memset(to,0,sizeof(to));
		for (int j=0;j<n;j++)
		for (int k=0;k<m;k++)
		if (a[i][j]==a[i-1][k]) to[1<<j]=1<<k;
		for (int j=1;j<(1<<n);j++) to[j]=to[j&(j-1)]|to[j&-j];
		for (int j=0;j<(1<<n);j++) if (~dp[i-1][to[j]]) dp[i][j]=dp[i-1][to[j]]+popcount[j]*b[i];
//		for (int j=0;j<(1<<n);j++) print(dp[i][j],' ');
//		puts("");
		m=a[i+1].size();
		int tmp=(1<<n)-1;
		for (int j=0;j<n;j++)
		for (int k=0;k<m;k++)
		if (a[i][j]==a[i+1][k]) tmp^=1<<j;
		for (int j=(1<<n)-1;j>=0;j--)
		for (int k=0;k<n;k++)
		if (tmp>>k&1) up(dp[i][j],dp[i][j|1<<k]);
	}
	print(dp[cnt][0]);
	
	return 0;
}