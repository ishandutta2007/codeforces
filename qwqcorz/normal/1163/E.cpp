#include<bits/stdc++.h>
using namespace std;
const int L=19;
const int N=1<<L;

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
int f[L],b[L];
int a[N],num=0,x=0;
void dfs(int now)
{
	if (now==x) return;
	dfs(now+1);
	print(num^=b[now],' ');
	dfs(now+1);
}
bool check(int x)
{
	for (int i=0;i<x;i++) if (f[i]==0) return 0;
	return 1;
}
void insert(int x)
{
	int tmp=x;
	for (int i=L-1;i>=0;i--)
	if (x>>i&1)
	{
		if (f[i]) x^=f[i];
			 else{f[i]=x,b[i]=tmp;break;}
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1,j=1;i<L;i++)
	{
		while (j<=n&&a[j]<(1<<i)) insert(a[j++]);
		if (check(i)) x=i;
	}
	print(x);
	print(0,' ');
	dfs(0);
	
	return 0;
}