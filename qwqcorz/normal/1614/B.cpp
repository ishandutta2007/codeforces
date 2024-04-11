#include<bits/stdc++.h>
#define ll long long
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
int a[N],p[N],x[N];
void GreenDay()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read(),p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return a[x]>a[y];});
	for (int i=1;i<=n;i++) x[p[i]]=(i%2?1:-1)*((i+1)/2),ans+=2LL*((i+1)/2)*a[p[i]];
	print(ans);
	for (int i=0;i<=n;i++) print(x[i]," \n"[i==n]);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}