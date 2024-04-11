#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;

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
int a[N],c[N];

signed main()
{
	int n=read(),k=read()-1,ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	sort(c+1,c+n);
	for (int i=1;i<n-k;i++) ans+=c[i];
	print(ans);

	return 0;
}