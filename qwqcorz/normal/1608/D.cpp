#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

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
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}

void GreenDay()
{
	ysgs(1e5);
	bool flag=0,flag1=1,flag2=1;
	int n=read(),lx=0,ly=0,rx=0,ry=0,tot=0;
	for (int i=1;i<=n;i++)
	{
		char a[2];
		scanf("%s",a);
		lx+=a[0]=='?';
		ly+=a[0]=='W';
		rx+=a[1]=='?';
		ry+=a[1]=='B';
		if (a[0]=='W'||a[1]=='B') flag1=0;
		if (a[0]=='B'||a[1]=='W') flag2=0;
		if (a[0]==a[1])
		{
			if (a[0]=='?') tot++;
					  else flag=1;
		}
	}
	int ans=0;
	for (int i=0;i<=n;i++) ans=(ans+1LL*C(lx,i-ly)*C(rx,i-ry))%p;
	if (!flag) ans=(ans+flag1+flag2-power(2,tot)+p)%p;
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}