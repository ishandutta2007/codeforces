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
int n,a[N],ans=0,f[N*2],t[N],p[N];
bool cmp(int x,int y)
{
	return t[x]>t[y];
}
int y;
int solve(int x)
{
	if (x==y) return 0;
	int ret=0;
	for (int i=-n;i<=n;i++) f[i+N]=n+1;
	f[N]=0;
	for (int i=1,sum=0;i<=n;i++)
	{
		if (a[i]==x) sum++;
		if (a[i]==y) sum--;
		ret=max(ret,i-f[sum+N]);
		f[sum+N]=min(f[sum+N],i);
	}
	return ret;
}
int rnd(int n)
{
	int ret=0;
	for (int i=1;i<=6;i++) ret=ret*10+rand()%10;
	return ret%n;
}
int rnd(int l,int r)
{
	if (l>r) return 1;
	return rnd(r-l+1)+l;
}

signed main()
{
	srand(time(0));
	n=read();
	for (int i=1;i<=n;i++) t[a[i]=read()]++;
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+1+n,cmp);
	y=p[1];
	for (int i=2;i<=233;i++) ans=max(ans,solve(p[i]));
	for (int i=1;i<=233;i++) ans=max(ans,solve(p[rnd(234,n)]));
	print(ans);

	return 0;
}