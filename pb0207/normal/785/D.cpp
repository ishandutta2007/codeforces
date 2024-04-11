#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,P=1e9+7;

char s[N];

ll n,fac[N],inv[N],l[N],r[N],ans;

ll qpow(ll a,ll b)
{
	ll ret=1ll;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

void pre()
{
	fac[0]=1ll;
	for(int i=1;i<=N-1;i++)
		fac[i]=(fac[i-1]*i)%P;
	inv[N-1]=qpow(fac[N-1],P-2);
	for(int i=N-2;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
}

ll C(ll n,ll m)
{
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int main()
{
	pre();
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		l[i]=l[i-1]+(s[i]=='(');
	for(int i=n;i>=1;i--)
		r[i]=r[i+1]+(s[i]==')');
	for(int i=1;i<=n;i++)
		if(s[i]=='(')
			ans=(ans+C(l[i]+r[i]-1,l[i]))%P;
	cout<<ans;
}