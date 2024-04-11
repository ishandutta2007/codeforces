#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=5e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>fac[N];
int a[N],miu[M],t[M];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),q=read(),m=0,tot=0;
	for (int i=1;i<=n;i++) m=max(m,a[i]=read());
	miu[1]=1;
	for (int i=1;i<=m;i++)
	for (int j=i+i;j<=m;j+=i) miu[j]-=miu[i];
	for (int i=1;i<=n;i++)
	for (int j=1;j*j<=a[i];j++)
	if (a[i]%j==0)
	{
		if (j>1) fac[i].push_back(j);
		if (j*j<a[i]) fac[i].push_back(a[i]/j);
	}
	ll ans=0;
	while (q--)
	{
		int x=read(),f=a[x]>0?1:-1; tot+=f;
		for (int i:fac[x])
		{
			if (f<0) t[i]--;
			ans+=miu[i]*f*t[i];
			if (f>0) t[i]++;
		}
		print(1LL*tot*(tot-1)/2+ans);
		a[x]=-a[x];
	}
	
	return 0;
}