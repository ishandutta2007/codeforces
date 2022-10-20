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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
mt19937 rnd(time(0));
int a[N];
int calc(int n,int x)
{
	int ret=0;
	for (int i=1;i<=n;i++) ret+=min(a[i]>=x?a[i]%x:n,x-a[i]%x);
	return ret;
}
int check(int n,int x)
{
	int ret=n;
	for (int i=2;i*i<=x;i++)
	if (x%i==0)
	{
		ret=min(ret,calc(n,i));
		while (x%i==0) x/=i;
	}
	if (x>1) ret=min(ret,calc(n,x));
	return ret;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),ans=n;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int T=25;T--;)
	{
		int x=a[rnd()%n+1];
		ans=min(ans,check(n,x-1));
		ans=min(ans,check(n,x));
		ans=min(ans,check(n,x+1));
	}
	print(ans);
	
	return 0;
}