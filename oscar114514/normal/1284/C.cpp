#include<bits/stdc++.h>
using namespace std;
int n,k;
int fac[277777];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%k;
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=1ll*(n-i+1)*(n-i+1)%k*fac[i]%k*fac[n-i]%k;
	ans%=k;
	cout<<ans<<endl;
	return 0;
}