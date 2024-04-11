#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[200069],dp[200069],ps[200069];

int main()
{
	long long i,k,p,e,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",a+i,&k,&e);
		p=lower_bound(a+1,a+i+1,k)-a;
		dp[i]=(a[i]-k+ps[i-1]+dv-ps[p-1])%dv;
		z=(z+dp[i]*e)%dv;
		ps[i]=(ps[i-1]+dp[i])%dv;
	}
	z=(z+a[n]+1)%dv;
	printf("%lld\n",z);
}