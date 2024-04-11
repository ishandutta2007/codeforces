//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll n,a[N],ans=0;
int main(){
	ll i,j,sum,mx;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[n]=0;
	for(i=1;i<n;i+=2)
	{
		a[i]=-a[i];
	}
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			ans+=min(a[i],-a[i+1]);
			continue;
		}
		sum=mx=0;
		for(j=i;j<n;j++)
		{
			sum+=a[j];
			mx=min(mx,sum);
			if(j%2==0)
			{
				if(min(a[i-1],-(a[j+1]+sum))+min(mx,sum)>=0)
				{
					ans+=min(a[i-1],-(a[j+1]+sum))+min(mx,sum)+1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}