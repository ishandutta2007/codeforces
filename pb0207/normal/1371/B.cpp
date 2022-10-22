#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int T;

ll n,r;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&r);
		ll ans=0; 
		ll a=min(n-1,r);
		ans=a*(a+1)/2;
		if(r>=n)
			ans++;
		printf("%lld\n",ans);
	} 
}