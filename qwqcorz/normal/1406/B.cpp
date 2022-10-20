#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int inf=243000000000000005ll;

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
int mn[N][6],mx[N][6],a[N];

signed main()
{
	memset(mn,0,sizeof(mn));
	memset(mx,0,sizeof(mx));
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=0;i<=5;i++)
		for (int j=i+1;j<=5;j++) mn[i][j]=inf,mx[i][j]=-inf;
		for (int i=0;i<=n;i++) mn[i][0]=mx[i][0]=1;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=min(i,5ll);j++)
		{
			mx[i][j]=max(mx[i-1][j],max(mx[i-1][j-1]*a[i],mn[i-1][j-1]*a[i]));
			mn[i][j]=min(mn[i-1][j],min(mx[i-1][j-1]*a[i],mn[i-1][j-1]*a[i]));
		}
		print(mx[n][5]);
	}

	return 0;
}