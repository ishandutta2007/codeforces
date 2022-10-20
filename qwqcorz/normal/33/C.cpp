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

int a[N],l[N],r[N];

int main()
{
	int n=read(),ans=0;
	l[0]=r[n+1]=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1,sum=0;i<=n;i++)
	{
		sum+=a[i];
		l[i]=max(-sum,l[i-1]+a[i]);
	}
	for (int i=n,sum=0;i>=1;i--)
	{
		sum+=a[i];
		r[i]=max(-sum,r[i+1]+a[i]);
	}
	for (int i=0;i<=n+1;i++) ans=max(ans,l[i]+r[i+1]);
	print(ans);

	return 0;
}