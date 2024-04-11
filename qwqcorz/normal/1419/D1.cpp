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
int a[N],b[N];

signed main()
{
	int n=read(),cnt=0,ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) if (i%2==0) b[i]=a[++cnt];
	for (int i=1;i<=n;i++) if (i%2==1) b[i]=a[++cnt];
	for (int i=2;i<n;i++) ans+=b[i]<b[i-1]&&b[i]<b[i+1];
	print(ans);
	for (int i=1;i<=n;i++) print(b[i],' ');

	return 0;
}