#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;

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
int a[N],ans[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	bool flag=1;
	for (int i=2;i<=n;i++) if (a[1]!=a[i]) flag=0;
	if (flag)
	{
		if (a[1]==0)
		{
			puts("YES");
			for (int i=1;i<=n;i++) print(1,' ');
			return 0;
		}
		else return puts("NO"),0;
	}
	int Max=*max_element(a+1,a+1+n),x=0;
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=2;i<=n*2;i++) if (a[i]==Max&&a[i]!=a[i-1]) x=i;
	if (x>n) x-=n;
	flag=0;
	ans[x]=a[x];
	for (int i=x-1;i>=1;i--)
	if (a[i]==0&&flag==0) ans[i]=ans[i+1]*2,flag=1;
	else ans[i]=ans[i+1]+a[i];
	ans[n+1]=ans[1];
	for (int i=n;i>x;i--)
	if (a[i]==0&&flag==0) ans[i]=ans[i+1]*2,flag=1;
	else ans[i]=ans[i+1]+a[i];
	puts("YES");
	for (int i=1;i<=n;i++) print(ans[i],' ');
	
	return 0;
}