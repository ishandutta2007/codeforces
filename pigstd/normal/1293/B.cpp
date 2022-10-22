#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
double dp[M];
int n;

int main()
{
	cin>>n;
	if (n==1)
	{
		cout<<"1.000000000000";
		return 0;
	}
	dp[1]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<2;j++)
			dp[i]=max(dp[i],dp[i-j]+(double)(j)/i);
	}
	printf("%.12lf",dp[n]);
	return 0;
}