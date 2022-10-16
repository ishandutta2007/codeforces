#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[200069],d;
bitset<200069> a;
priority_queue<pair<long long,long long>> pq,mn;

int main()
{
	long long i;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	mn.push({0,d+1});
	for(i=1;i<=n;i++)
	{
		for(;!pq.empty()&&pq.top().sc<i;pq.pop());
		for(;!mn.empty()&&mn.top().sc<i;mn.pop());
		dp[i]=dp[i-1]+i;
		if(a[i])
		{
			pq.push({mn.top().fr-i,i+d});
		}
		if(!pq.empty())
		{
			dp[i]=min(dp[i],-pq.top().fr);
		}
		mn.push({-dp[i],i+d+1});
	}
	printf("%lld\n",dp[n]);
}