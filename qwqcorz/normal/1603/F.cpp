#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int p=998244353;
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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int pw[N],inv[N];
void TheBeatles()
{
	int n=read(),k=read(),x=read();
	if (x)
	{
		int ans=0,now=inv[k];
		for (int i=1,zyk=power(2,n);i<=k;i++,zyk=1LL*zyk*inv2%p)
		{
			now=1LL*now*(pw[k]-pw[i-1]+p)%p;
			ans=(ans+now)%p;
			now=1LL*now*(zyk-1)%p*inv[i]%p;
		}
		print(ans);
	}
	else
	{
		int ans=1;
		for (int i=1;i<=min(n,k+1);i++) ans=1LL*ans*(pw[k]-pw[i-1]+p)%p;
		print(ans);
	}
}
void ysgs(int n)
{
	for (int i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*2%p;
	int mul=1;
	for (int i=1;i<=n;i++) mul=1LL*mul*(pw[i]-1)%p;
	mul=power(mul,p-2);
	for (int i=1;i<=n;i++) inv[i]=mul;
	for (int i=1,mul=1;i<=n;mul=1LL*mul*(pw[i++]-1)%p) inv[i]=1LL*inv[i]*mul%p;
	for (int i=n,mul=1;i>=1;mul=1LL*mul*(pw[i--]-1)%p) inv[i]=1LL*inv[i]*mul%p;
}

signed main()
{
	ysgs(1e7);
	int T=read();
	while (T--) TheBeatles();
	
	return 0;
}