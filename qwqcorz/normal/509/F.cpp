#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int P=1e9+7;

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
int p[N],f[N][N],g[N][N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int i=1;i<=n;i++) g[i][i]=1;
	for (int i=2;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	{
		int l=j,r=i+j-1;
		for (int k=l;k<r;k++)
		{
			if (p[k+1]<p[r+1])
			g[l][r]=(g[l][r]+1LL*g[l][k]*f[k+1][r])%P;
			f[l][r]=(f[l][r]+1LL*g[l][k]*f[k+1][r])%P;
		}
	}
	print(f[1][n]);
	
	return 0;
}