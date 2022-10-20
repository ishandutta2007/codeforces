#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int power(int a,long long b)
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
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<0||m<0||n<m) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	ysgs(2e5);
	while (T--)
	{
		int n=read(),k=read(),x=0;
		for (int i=0;i<n;i++) if (i%2==0) add(x,C(n,i));
		if (n&1) print(power(x+1,k));
		else
		{
			int ans=power(x,k);
			for (int i=0;i<k;i++) add(ans,1LL*power(x,i)*power(2,1LL*(k-i-1)*n)%p);
			print(ans);
		}
	}
	
	return 0;
}