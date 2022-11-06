#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		vector<long long> ans(n+n+5),sum(n+n+5),pinv2(n+5);
		long long inv2=poww(2,MOD-2);
		pinv2[0]=1;
		for(int i=1;i<=n;i++)pinv2[i]=pinv2[i-1]*inv2%MOD;
		for(int i=n;i>=2;i--)
		{
			if(i==n)ans[i]=1;
			else ans[i]=inv2;
			ans[i]=ans[i]*pinv2[(i-1)/2]%MOD*(1+sum[i*2])%MOD;
			sum[i]=(sum[i+1]-ans[i]+MOD)%MOD;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<"\n";
		}
	}
	
	return 0;
}