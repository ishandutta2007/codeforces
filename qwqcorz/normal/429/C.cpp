#include<bits/stdc++.h>
using namespace std;
const int N=25;
const int S=1<<11;

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
vector<int>a;
int popcount[S],high[S];
bool dp[S][N];
inline bool ck(int x,int y)
{
	if (!x) return dp[x][y];
	return dp[x][y]&&a[high[x]]==popcount[x]+y;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x>1) a.push_back(x);
			else m++;
	}
	if (n==1) return puts(m==1?"YES":"NO"),0;
	if (n==2) return puts("NO"),0;
	n=a.size();
	if (m<n+1) return puts("NO"),0;
	sort(a.begin(),a.end(),greater<int>());
	if (a[0]!=n+m) return puts("NO"),0;
	for (int i=0;i<n;i++) high[1<<i]=i;
	for (int i=1;i<(1<<n);i++)
	{
		high[i]=high[i&-i];
		popcount[i]=popcount[i&(i-1)]+1;
	}
	dp[0][1]=1;
	for (int i=1;i<(1<<n);i++)
	for (int j=1;j<=m;j++)
	{
		int h=high[i],all=i^(1<<h);
		for (int s=all;;s=(s-1)&all)
		{
			for (int k=0;k<=j;k++)
			dp[i][j]|=(dp[s|(1<<h)][k]||ck(s,k))&&ck(all^s,j-k);
			if (!s) break;
		}
	}
	puts(dp[(1<<n)-1][m]?"YES":"NO");
	
	return 0;
}