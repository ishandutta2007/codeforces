#include <iostream>
#include <algorithm>

using namespace std;

long long a[3],dp[4001];
bool dpb[4001];

long long bf(long long n)
{
	if(n==0)
	{
		return 0;
	}
	if(n<0)
	{
		return -6969;
	}
	if(!dpb[n])
	{
		long long i,k=-6969;
		
		for(i=0;i<3;i++)
		{
			k=max(k,bf(n-a[i]));
		}
		dpb[n]=true;
		dp[n]=k+1;
	}
	return dp[n];
}

int main()
{
	long long n;
	
	cin>>n>>a[0]>>a[1]>>a[2];
	cout<<bf(n)<<'\n';
}