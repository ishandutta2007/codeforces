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
void NO()
{
	puts("NO");
	exit(0);
}
bool calc(bool x,bool y)
{
	if (x==1&&y==0) return 0;
	return 1;
}
bool a[N];
int l[N],r[N];
void solve(int n)
{
	bool now=0;
	for (int i=n-2;i>=1;i--)
	now=calc(a[i],now);
	if (now==0) NO();
	for (int i=1;i<=n-2;i++) l[i]++;
	r[n-1]=n-2;
}

signed main()
{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n==1)
	{
		if (a[1]==1) NO();
		puts("YES");
		print(a[1]);
		return 0;
	}
	if (n==2)
	{
		if (a[1]==1&&a[2]==0)
		{
			puts("YES");
			printf("%d->%d",a[1],a[2]);
			return 0;
		}
		else NO();
	}
	if (a[n]==1) NO();
	if (a[n]==0&&a[n-1]==1);
	if (a[n]==0&&a[n-1]==0&&a[n-2]==1) solve(n);
	if (a[n]==0&&a[n-1]==0&&a[n-2]==0) l[n-2]++,r[n-1]++;
	puts("YES");
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=l[i];j++) putchar('(');
		write(a[i]);
		for (int j=1;j<=r[i];j++) putchar(')');
		putchar('-');
		putchar('>');
	}
	print(a[n]);

	return 0;
}