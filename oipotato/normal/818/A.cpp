#include<iostream>
using namespace std;
long long n,k,ans;
int main()
{
	cin>>n>>k;
	ans=n/2/(k+1);
	if(ans)cout<<ans<<' '<<k*ans<<' '<<n-ans*(k+1);
	else cout<<0<<' '<<0<<' '<<n;
	return 0;
}