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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct BIT
{
	int t[N],n;
	void send(int _n)
	{
		n=_n;
		memset(t,0,sizeof(t));
	}
	void add(int x,int y)
	{
		for (;x<=n;x+=x&-x) t[x]=max(t[x],y);
	}
	int query(int x)
	{
		int ret=0;
		for (;x;x=(x-1)&x) ret=max(ret,t[x]);
		return ret;
	}
}t;
int a[N],f[N],g[N];

signed main()
{
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		int l=read(),r=read();
		a[l]++;
		a[r+1]--;
	}
	for (int i=1;i<=m+1;i++) a[i]+=a[i-1];
	for (int i=1;i<=m;i++) a[i]++;
	t.send(n+1);
	for (int i=1;i<=m;i++)
	{
		f[i]=t.query(a[i])+1;
		t.add(a[i],f[i]);
	}
	t.send(n+1);
	for (int i=m;i>=1;i--)
	{
		g[i]=t.query(a[i])+1;
		t.add(a[i],g[i]);
	}
	for (int i=1;i<=m;i++) ans=max(ans,f[i]+g[i+1]);
	print(ans);
	
	return 0;
}