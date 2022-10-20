#include<bits/stdc++.h>
using namespace std;
const int N=505;

int get()
{
	char c=getchar();
	while (c!='W'&&c!='B') c=getchar();
	return c=='B';
}
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
int a[N][N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		int x=get();
		if (x) a[i][j]^=1,a[i-1][j]^=1,a[i][j-1]^=1,a[i-1][j-1]^=1;
	}
	int sum=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) sum+=a[i][j];
	int ans=sum;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		int t=a[i][j],k=1;
		if (i<n) t+=a[n][j],k++;
		if (j<m) t+=a[i][m],k++;
		if (i<n&&j<m) t+=a[n][m],k++;
		ans=min(ans,sum-t+(k-t)+3);
	}
	print(ans);
	
	return 0;
}