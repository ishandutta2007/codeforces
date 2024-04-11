#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll n,fact[N],inv[N];
char s[N];
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv[y]*inv[x-y])%mod))%mod;
}
int main(){
	ll T,i,j,num0,num2;
	fact[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=ksm(fact[i],mod-2);
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		scanf("%s",&s);
		num0=num2=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				num0++;
				continue;
			}
			for(j=i;j<n;j++)
			{
				if(s[j]=='0')
				{
					break;
				}
			}
			num2+=(j-i)/2;
			i=j-1;
		}
		printf("%lld\n",GetC(num0+num2,num0));//put num2 same parts in num0+1 places -> divide num2 things into num0+1 groups with at least 0 in each
	}
	return 0;
}