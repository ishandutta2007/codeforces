#include<bits/stdc++.h>
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=1e6+5;

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
char s[N];
piir f[N],g[N];
int a[N],sum[N];
void rock(int n,int len,int k)
{
	for (int i=len;i<=n;i++)
	{
		f[i]=mk(g[i-len].fi+sum[i]-sum[i-len]-k,g[i-len].se+1);
		g[i]=max(g[i-1],f[i]);
	}
}
int solve(int n,int k,int len)
{
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=1e6;
	while (l<=r)
	{
		int mid=(l+r)/2;
		rock(n,len,mid);
		if (g[n].se<k) r=mid-1;
				  else l=mid+1;
	}
	rock(n,len,r);
//	for (int i=1;i<=n;i++) putchar(a[i]+'0');;puts("");
//	print(g[n].fi,' ');
//	print(g[n].se);
//	print(r);
//	print(sum[n]);
//	for (int i=1;i<=n;i++) print(f[i].fi,','),print(f[i].se,' ');;puts("");
//	for (int i=1;i<=n;i++) print(g[i].fi,','),print(g[i].se,' ');;puts("");
	return sum[n]-(g[n].fi+r*k);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read(),l=read(),ans;
	if (1LL*k*l>=n) return puts("0"),0;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]='A'<=s[i]&&s[i]<='Z';
	ans=solve(n,k,l);
	for (int i=1;i<=n;i++) a[i]^=1;
	ans=min(ans,solve(n,k,l));
	print(ans);
	
	return 0;
}