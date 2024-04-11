#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[1001];
ll n,ans=0;
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=2;i<n;i++)
	{
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
		{
			a[i+1]=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}