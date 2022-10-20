#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
double ans=-1;
int a[N];
double calc(int i,int j,int k)
{
	return (1.0*a[k]-1.0*a[j])/(1.0*a[k]-1.0*a[i]);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int l=1,r=3;l<=n-2;l++)
	{
		while (r<n&&a[r+1]-a[l]<=m) r++;
		if (r-l>=2&&a[r]-a[l]<=m) ans=max(ans,calc(l,l+1,r));
	}
	if (ans<0) puts("-1");
		  else printf("%.10lf",ans);

	return 0;
}