#include<bits/stdc++.h>
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
bool a[N][N];
int sum1[N*2][N],sum2[N*2][N],n,m,q,mx1[N*2],mx2[N*2],d[N][N],dd[N][N];
int calc1(int x,int l,int r){return x<N&&x>=-N&&max(l,1)<=min(r,mx1[x+N])?sum1[x+N][min(r,mx1[x+N])]-sum1[x+N][max(l,1)-1]:0;}
int calc2(int x,int l,int r){return x<N*2&&x>=0&&max(l,1)<=min(r,mx2[x])?sum2[x][min(r,mx2[x])]-sum2[x][max(l,1)-1]:0;}

signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) mx1[i-j+N]=mx2[i+j]=i,sum1[i-j+N][i]=sum2[i+j][i]=a[i][j]=1;
	for (int i=1-m+N;i<=n-1+N;i++)
	for (int j=1;j<=mx1[i];j++) sum1[i][j]+=sum1[i][j-1];
	for (int i=2;i<=n+m;i++)
	for (int j=1;j<=mx2[i];j++) sum2[i][j]+=sum2[i][j-1];
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read(),ans=d[x][y];
		for (int j=0;;j++)
		{
			ans=j;
			if (calc1(x-y-j,x-j,x)) break;
			if (calc1(x-y+j,x,x+j)) break;
			if (calc2(x+y-j,x-j,x)) break;
			if (calc2(x+y+j,x,x+j)) break;
		}
		if (ans>d[x][y]) dd[x][y]=1;
		d[x][y]=ans;
		int ax=0,ay=0;
		for (int j=max(x-ans,dd[x][y]);j<=min(x+ans,n);j++)
		{
			dd[x][y]=j;
			if (y-(ans-abs(x-j))>=1&&a[j][y-(ans-abs(x-j))]){ax=j,ay=y-(ans-abs(x-j));break;}
			if (y+(ans-abs(x-j))<=m&&a[j][y+(ans-abs(x-j))]){ax=j,ay=y+(ans-abs(x-j));break;}
		}
		if (!ax) puts("-1");
			else print(ax,' '),print(ay);
		a[ax][ay]=0;
		for (int j=ax;j<=mx1[ax-ay+N];j++) sum1[ax-ay+N][j]--;
		for (int j=ax;j<=mx2[ax+ay];j++) sum2[ax+ay][j]--;
	}
	
	return 0;
}