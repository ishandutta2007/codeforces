#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0;
bool a[N][N],l[N][N],r[N][N],u[N][N],d[N][N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char c=getchar();
		while (c!='.'&&c!='#') c=getchar();
		a[i][j]=c=='.';
	}
	memset(l,1,sizeof(l));
	memset(r,1,sizeof(r));
	memset(u,1,sizeof(u));
	memset(d,1,sizeof(d));
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		l[i][j]=l[i][j-1]&&a[i][j],
		u[i][j]=u[i-1][j]&&a[i][j];
	for (int i=n;i>=1;i--)
	for (int j=m;j>=1;j--)
		r[i][j]=r[i][j+1]&&a[i][j],
		d[i][j]=d[i+1][j]&&a[i][j];
	for (int i=2;i<n;i++) ans+=r[i][1];
	for (int i=2;i<m;i++) ans+=d[1][i];
	for (int i=2;i<n;i++)
	for (int j=2;j<m;j++)
		ans+=l[i][j]&&d[i][j],
		ans+=l[i][j]&&u[i][j],
		ans+=r[i][j]&&d[i][j],
		ans+=r[i][j]&&u[i][j];
	for (int i=2;i<n;i++)
	for (int j=3;j<m;j++)
		ans+=u[i][j]&&d[i][j-1],
		ans+=d[i][j]&&u[i][j-1];
	for (int i=3;i<n;i++)
	for (int j=2;j<m;j++)
		ans+=l[i][j]&&r[i-1][j],
		ans+=r[i][j]&&l[i-1][j];
	for (int i=2;i<n;i++)
	for (int j=2,tot=0,sum=0;j<m;j++)
	if (a[i][j]==0) tot=sum=0;
	else if (++tot>=3) sum+=u[i][j-2]+d[i][j-2],ans+=(u[i][j]+d[i][j])*sum;
	for (int j=2;j<m;j++)
	for (int i=2,tot=0,sum=0;i<n;i++)
	if (a[i][j]==0) tot=sum=0;
	else if (++tot>=3) sum+=l[i-2][j]+r[i-2][j],ans+=(l[i][j]+r[i][j])*sum;
	print(ans);
	
	return 0;
}