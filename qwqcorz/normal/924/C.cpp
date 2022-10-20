#include<bits/stdc++.h>
#define int long long
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
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	for (int i=1;i<=n;i++) b[i]=max(b[i],b[i-1]);
	for (int i=n;i>=1;i--) b[i-1]=max(b[i-1],b[i]-1);
	for (int i=1;i<=n;i++) ans+=b[i]-a[i];
	print(ans);

	return 0;
}