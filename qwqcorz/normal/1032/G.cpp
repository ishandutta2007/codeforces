#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int LOG=21;

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
int Log[N];
int a[N],l[N][LOG],r[N][LOG];
struct rmq
{
	int st[N][LOG],val[N];
	inline int Max(int x,int y)
	{
		return val[x]<val[y]?y:x;
	}
	void build(int n,int type)
	{
		for (int i=1;i<=n;i++) st[i][0]=i;
		for (int i=1;i<=n;i++) val[i]=type*(type<0?l[i][0]:r[i][0]);
		for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++)
		st[i][j]=Max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r)
	{
		int k=Log[r-l+1];
		return Max(st[l][k],st[r-(1<<k)+1][k]);
	}
}Min,Max;

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=a[i+n]=a[i+n*2]=read();
	if (n==1) return puts("0"),0;
	Log[1]=0;
	for (int i=2;i<=n*3;i++) Log[i]=Log[i/2]+1;
	for (int i=1;i<=n*3;i++) l[i][0]=max(i-a[i],1  );
	for (int i=1;i<=n*3;i++) r[i][0]=min(i+a[i],n*3);
	Min.build(n*3,-1);
	Max.build(n*3, 1);
	for (int j=1;j<=20;j++)
	for (int i=1;i<=n*3;i++)
	{
		int x=Min.query(l[i][j-1],r[i][j-1]);
		int y=Max.query(l[i][j-1],r[i][j-1]);
		l[i][j]=min(l[x][j-1],l[y][j-1]);
		r[i][j]=max(r[x][j-1],r[y][j-1]);
	}
	for (int i=n+1;i<=n*2;i++)
	{
		int L=i,R=i,ans=0;
		for (int j=20;j>=0;j--)
		{
			if (max(r[L][j],r[R][j])-min(l[L][j],l[R][j])+1>=n) continue;
			int nL=Min.query(l[L][j],r[R][j]);
			int nR=Max.query(l[L][j],r[R][j]);
			L=nL;
			R=nR;
			ans|=1<<j;
		}
		print(ans+1,' ');
	}

	return 0;
}