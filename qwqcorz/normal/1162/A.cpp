#include<bits/stdc++.h>
using namespace std;
const int N=55;

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
int a[N];

signed main()
{
	int n=read(),h=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=h;
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read(),h=read();
		for (int j=l;j<=r;j++) a[j]=min(a[j],h);
	}
	for (int i=1;i<=n;i++) ans+=a[i]*a[i];
	print(ans);

	return 0;
}