#include<bits/stdc++.h>
using namespace std;
const int N=28;
const int inf=INT_MAX/2;

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
int n,l,r,x,a[N],ans=0;
void dfs(int now,int tot,int sum,int Min,int Max)
{
	if (now>n) return void(ans+=tot>=2&&l<=sum&&sum<=r&&Max-Min>=x);
	dfs(now+1,tot,sum,Min,Max);
	dfs(now+1,tot+1,sum+a[now],min(Min,a[now]),max(Max,a[now]));
}

signed main()
{
	n=read();
	l=read();
	r=read();
	x=read();
	for (int i=1;i<=n;i++) a[i]=read();
	dfs(1,0,0,inf,0);
	print(ans);

	return 0;
}