#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e6+1e3+7,P=998244353;

int n,a[N],k;

ll ans1,ans2;

ll fac[N],inv[N];

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

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=n-k+1;i--)
		ans1+=i;
	ll ct=0;
	ans2=1;
	int t=0;
	for(t=1;t<=n;t++)
		if(a[t]>=n-k+1)
			break;
	for(int i=t+1;i<=n;i++)
	{
		ct++;
		if(a[i]>=n-k+1)
			ans2=ans2*ct%P,ct=0;
	}
	printf("%lld %lld\n",ans1,ans2);
}