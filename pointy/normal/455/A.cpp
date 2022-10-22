#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[100005];
long long a[100005];
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i=1;i<=100000;i++)
	{
		if (i>1) dp[i]=dp[i-2];
		if (i>2) dp[i]=max(dp[i],dp[i-3]);
		dp[i]+=a[i]*i;
	}
	cout << max(dp[100000],dp[99999]);
	return 0;
}
//.................