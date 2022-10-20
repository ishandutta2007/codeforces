#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
	memset(a,0,sizeof(a));
	int n=read(),k=read(),tot=n/2+n%2,sum=0,ans=0;
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=1;i<=k;i++)
	while (tot&&a[i]>=2)
	{
		tot--;
		a[i]-=2;
		ans+=2;
	}
	for (int i=1;i<=k;i++) sum+=a[i];
	print(ans+min(sum,tot));

	return 0;
}