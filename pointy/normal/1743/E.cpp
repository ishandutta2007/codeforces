// Author: Little09
// Problem: E. FTL
// Contest: Educational Codeforces Round 137 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1743/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const ll inf=1e18;
ll p1,t1,p2,t2,h,s;
ll f[N],dp[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	for (int i=0;i<N;i++) f[i]=inf,dp[i]=inf;
	for (int i=0;(p1-s)*i<=h;i++) 
	{
		ll len=t1*(i+1);
		ll j=len/t2-1;
		if (j<0) continue;
		ll sum=(p1-s)*i+(p2-s)*j+p1+p2-s;
		sum=min(sum,h);
		f[sum]=min(f[sum],len);
	}
	for (int i=0;(p2-s)*i<=h;i++) 
	{
		ll len=t2*(i+1);
		ll j=len/t1-1;
		if (j<0) continue;
		ll sum=(p2-s)*i+(p1-s)*j+p2+p1-s;
		sum=min(sum,h);
		f[sum]=min(f[sum],len);
	}
	f[p1-s]=min(f[p1-s],t1);
	f[p2-s]=min(f[p2-s],t2);
	dp[0]=0;
	for (int i=N-2;i>=0;i--) f[i]=min(f[i],f[i+1]);
	for (int i=1;i<=h;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i]=min(dp[i],dp[i-j]+f[j]);
		}
	}
	cout << dp[h] << endl;
	return 0;
}