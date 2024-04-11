#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=25;
const int p=1e9+7;

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
int a[N],inv[N];
int C(int n,int m)
{
	int ret=1;
	for (int i=1;i<=m;i++) ret=ret*((n-i+1)%p)%p*inv[i]%p;
	return ret;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	inv[1]=1;
	for (int i=2;i<=20;i++) inv[i]=inv[p%i]*(p-p/i)%p;
	int n=read(),m=read(),ans=0;
	for (int i=0;i<n;i++) a[i]=read();
	for (int s=0;s<(1<<n);s++)
	{
		int now=m,flag=1;
		for (int i=0;i<n;i++) if (s>>i&1) now-=a[i]+1,flag*=-1;
		if (now<0) continue;
		ans+=C(now+n-1,n-1)*flag;
	}
	print((ans%p+p)%p);
	
	return 0;
}