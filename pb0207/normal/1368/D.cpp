#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int n;

ll a[N],b[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<20;i++)
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				b[i]++;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll x=0;
		for(int j=0;j<20;j++)
			if(b[j])
				x+=1ll<<j,b[j]--;
		ans+=x*x;
	}
	printf("%lld\n",ans);
}