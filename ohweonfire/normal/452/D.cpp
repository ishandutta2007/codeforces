#include <iostream>
#include <algorithm>
using namespace std;
int dp[10002],k,n1,n2,n3,t1,t2,t3;
int main()
{
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	for(int i=1;i<=k;i++)
	{
		dp[i]=t1+t2+t3;
		if(n1<i)dp[i]=max(dp[i],dp[i-n1]+t1);
		if(n2<i)dp[i]=max(dp[i],dp[i-n2]+t2);
		if(n3<i)dp[i]=max(dp[i],dp[i-n3]+t3);
	}
	cout<<dp[k]<<endl;
	return 0;
}