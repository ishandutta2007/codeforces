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
int ans=0,x[N],y[N],z[N];
int a[N];
bool check(int n)
{
	for (int i=2;i<=n;i++) if (a[i]!=a[1]) return 0;
	return 1;
}
void XOR(int u,int v,int w)
{
	int X=a[u]^a[v]^a[w];
	a[u]=a[v]=a[w]=X;
	++ans;
	x[ans]=u;
	y[ans]=v;
	z[ans]=w;
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n%2==0) XOR(n-2,n-1,n);
	for (int i=1;i+2<=n;i+=2) XOR(i,i+1,i+2);
	for (int i=n-!(n&1)-2;i>=3;i-=2) XOR(i-2,i-1,i);
	if (check(n))
	{
		puts("YES");
		print(ans);
		for (int i=1;i<=ans;i++)
		{
			print(x[i],' ');
			print(y[i],' ');
			print(z[i]);
		}
	}
	else puts("NO");

	return 0;
}