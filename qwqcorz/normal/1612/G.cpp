#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int p=1e9+7;
const int inv2=(p+1)/2;

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
int C[N*2],*c=&C[N];
int fact[N];
ll calc(ll l,ll r){return 1LL*(r-l+1)%p*((l+r)%p)%p*inv2%p;}
void GreenDay()
{
	ll cnt=0;
	int n=read(),ans=0,tot=1;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		c[1-x]++;
		c[x+1]--;
	}
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=-1e6;i<=1e6;i++)
	{
		c[i]+=c[i-2];
		ans=(ans+1LL*(i+p)*calc(cnt,cnt+c[i]-1))%p;
		tot=1LL*tot*fact[c[i]]%p;
		cnt+=c[i];
//		if (c[i]) print(i,':'),print(c[i]);
	}
	print(ans,' '),print(tot);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}