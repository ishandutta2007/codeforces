#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 10000000000
#define N 110
using namespace std;
ll n,a[N],sumz=0,sumo=0,ans=0;
int main(){
	ll i,os=0,zs=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			sumz++;
		}
		else
		{
			sumo++;
		}
	}
	ans=zs+sumo-os;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			zs++;
		}
		else
		{
			os++;
		}
		ans=max(ans,zs+sumo-os);
	}
	printf("%lld\n",ans);
	return 0;
}