#include <bits/stdc++.h>
#define N 3005
using namespace std;
int n,a[N],b[N],c[N],dp[N][2];
int main(){
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>c[i];
	}
	dp[0][0]=a[0];
	dp[0][1]=b[0];
	for(i=1;i<n;i++)
	{
		dp[i][0]=max(a[i]+dp[i-1][1],b[i]+dp[i-1][0]);
		dp[i][1]=max(b[i]+dp[i-1][1],c[i]+dp[i-1][0]);
	}
	cout<<dp[n-1][0]<<endl;
	return 0;
}