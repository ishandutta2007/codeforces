#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7,P=998244353;

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int n;

ll c[N],s[N];

bool cmp(int a,int b)
{
	return a>b;
} 

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		s[i]=(s[i-1]+c[i])%P; 
	ll ans;
	for(int k=1;k<=n;k++)
	{
		ans=0;
		for(int i=1;i<=n;i+=k)
		{
			int nx=min(i+k-1,n);
			ans=(ans+(s[nx]-s[i-1]+P)%P*((i-1)/k)%P)%P;
		}
		printf("%lld\n",ans*qpow(n,P-2)%P);
	}
}