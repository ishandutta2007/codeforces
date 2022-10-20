#include<bits/stdc++.h>
using namespace std;
const int N=405;

int get()
{
	char c=getchar();
	while (c!='0'&&c!='1') c=getchar();
	return c-'0';
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
int a[N][N],sumh[N][N],suml[N][N],sum[N][N];
int calc(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),ans=N*N;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			sum[i][j]=a[i][j]=get(),
			suml[i][j]=suml[i-1][j]+a[i][j],
			sumh[i][j]=sumh[i][j-1]+a[i][j];
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) sum[i][j]+=sum[i-1][j];
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) sum[i][j]+=sum[i][j-1];
		for (int i=1;i<=n;i++)
		for (int j=i+4;j<=n;j++)
		for (int k=4,mn=N*N;k<=m;k++)
		{
			int now=k-1-sumh[i][k-1]+k-1-sumh[j][k-1];
			now+=calc(i+1,1,j-1,k-1)+j-i-1-(suml[j-1][k]-suml[i][k]);
			int lst=k-3,tmp=-(lst-sumh[i][lst]+lst-sumh[j][lst]);
			tmp+=-calc(i+1,1,j-1,lst)+j-i-1-(suml[j-1][lst]-suml[i][lst]);
			mn=min(mn,tmp);
			ans=min(ans,now+mn);
		}
		print(ans);
	}
	
	return 0;
}