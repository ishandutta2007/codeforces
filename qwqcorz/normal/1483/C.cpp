#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
const int inf=1LL<<60;

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
int n;
int h[N],b[N];
int l[N],r[N],st[N],top;
int t[N],dp[N];
void add(int x,int y)
{
	for (;x;x-=x&-x) t[x]=max(t[x],y);
}
int query(int x)
{
	int ret=-inf;
	for (;x<=n+1;x+=x&-x) ret=max(ret,t[x]);
	return ret;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) h[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	st[top=0]=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&h[st[top]]>=h[i]) top--;
		l[i]=st[top];
		st[++top]=i;
	}
	st[top=0]=n+1;
	for (int i=n;i>=1;i--)
	{
		while (top&&h[st[top]]>=h[i]) top--;
		r[i]=st[top];
		st[++top]=i;
	}
	int ans=-inf;
	memset(t,0xc0,sizeof(t));
	add(1,0);
	for (int i=1;i<=n;i++)
	{
		dp[i]=query(l[i]+1)+b[i];
		add(r[i],dp[i]);
		if (r[i]>n) ans=max(ans,dp[i]);
	}
	print(ans);

	return 0;
}