#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
int a[N],sum[N],p[N],v[N],l[N],r[N];
bool cmp(int x,int y)
{
	return sum[x]-2ll*a[x]<sum[y]-2ll*a[y];
}
void del(int x)
{
	r[l[x]]=r[x];
	l[r[x]]=l[x];
}

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;i++) v[i]=sum[p[i]]-2ll*a[p[i]];
	r[0]=p[1];
	for (int i=1;i<=n;i++) l[p[i]]=p[i-1];
	for (int i=1;i<=n;i++) r[p[i]]=p[i+1];
	for (int i=1;i<=n;i++)
	{
		int now=r[0];
		while (now&&sum[now]-2ll*a[now]<=a[i]+sum[i])
		{
			if (now-i>=2&&sum[now-1]-sum[i]==(a[i]^a[now])) ans++;
			now=r[now];
		}
		del(i);
	}
	print(ans);

	return 0;
}