#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl=0,a[100069],dp[100069];
deque<long long> dq;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	dq.push_back(0);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
		for(;!dq.empty()&&a[dq.back()]>=a[i];dq.pop_back());
		dq.push_back(i);
		for(;dq.front()<=i-d;dq.pop_front());
		dp[i]=max(dp[i-1],dp[max(i-d,0ll)]+a[dq.front()]);
	}
	printf("%lld\n",ttl-dp[n]);
}