#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[5][N],id[5][N],sum[5][N],v[N],s[N];
bool left(int *x,int *l,int *r,int k)
{
	x[k]--;
	int mn=k;
	for (int i=1;i<=4;i++)
	if (x[i]<r[i]&&a[i][x[i]+1]<a[mn][x[mn]+1]) mn=i;
	x[mn]++;
	return mn!=k;
}
void right(int *x,int *l,int *r,int k)
{
	x[k]++;
	int mx=0;
	for (int i=1;i<=4;i++)
	if (i!=k&&x[i]>l[i]&&(!mx||a[i][x[i]]>a[mx][x[mx]])) mx=i;
	x[mx]--;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		v[i]=read();
		int x=read(),y=read();
		s[i]=y<<1|x;
	}
	int n1=0,n2=0,n3=0,n4=0;
	for (int i=1;i<=n;i++)
	if (s[i]==3) a[1][++n1]=v[i],id[1][n1]=i;
	else if (s[i]==1) a[2][++n2]=v[i],id[2][n2]=i;
	else if (s[i]==2) a[3][++n3]=v[i],id[3][n3]=i;
	else a[4][++n4]=v[i],id[4][n4]=i;
	sort(a[1]+1,a[1]+1+n1);
	sort(a[2]+1,a[2]+1+n2);
	sort(a[3]+1,a[3]+1+n3);
	sort(a[4]+1,a[4]+1+n4);
	sort(id[1]+1,id[1]+1+n1,[&](int x,int y){return v[x]<v[y];});
	sort(id[2]+1,id[2]+1+n2,[&](int x,int y){return v[x]<v[y];});
	sort(id[3]+1,id[3]+1+n3,[&](int x,int y){return v[x]<v[y];});
	sort(id[4]+1,id[4]+1+n4,[&](int x,int y){return v[x]<v[y];});
	int inf=2e9+7,ans=inf;
	int l[5]={0,0,0,0,0},r[5]={n,n1,n2,n3,n4},x[5]={m,0,0,0,0},alb[5];
	for (int i=1;i<=n;i++) a[0][i]=1e9+7;
	for (int i=1;i<=4;i++)
	for (int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[i][j];
	for (int i=0;i<=min(k,n1);i++)
	{
		if (k-i>n2||k-i>n3||m-i-(k-i)-(k-i)<0) continue;
		if (x[0])
		{
			x[0]=m-i-(k-i)-(k-i);
			x[1]=i;
			x[2]=k-i;
			x[3]=k-i;
			while (x[0]) assert(left(x,l,r,0));
		}
		l[1]=i,l[2]=l[3]=k-i;
		if (x[1]<l[1]) right(x,l,r,1);
		while (l[2]<x[2]&&left(x,l,r,2));
		while (l[3]<x[3]&&left(x,l,r,3));
		for (int i=1;i<=4;i++)
		{
			assert(l[i]<=x[i]);
			assert(x[i]<=r[i]);
		}
		int now=0;
		for (int i=1;i<=4;i++) now+=sum[i][x[i]];
		if (ans>now)
		{
			ans=now;
			memcpy(alb,x,sizeof(x));
		}
	}
	if (ans<inf)
	{
		print(ans);
		for (int i=1;i<=4;i++)
		for (int j=1;j<=alb[i];j++)
		print(id[i][j],' ');
	}
	else puts("-1");
	
	return 0;
}