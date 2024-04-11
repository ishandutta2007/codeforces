#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int a[4][N],sum[4][N],v[N],s[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		v[i]=read();
		int x=read(),y=read();
		s[i]=y<<1|x;
	}
	int n1=0,n2=0,n3=0;
	for (int i=1;i<=n;i++)
	if (s[i]==3) a[1][++n1]=v[i];
	else if (s[i]==1) a[2][++n2]=v[i];
	else if (s[i]==2) a[3][++n3]=v[i];
	sort(a[1]+1,a[1]+1+n1);
	sort(a[2]+1,a[2]+1+n2);
	sort(a[3]+1,a[3]+1+n3);
	int inf=2e9+7,ans=inf;
	for (int i=1;i<=3;i++)
	for (int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[i][j];
	for (int i=0;i<=min(k,n1);i++)
	{
		if (k-i>n2||k-i>n3) continue;
		ans=min(ans,sum[1][i]+sum[2][k-i]+sum[3][k-i]);
	}
	print(ans<inf?ans:-1);
	
	return 0;
}