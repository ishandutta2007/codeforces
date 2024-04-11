#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=3e6+1e3+7;

typedef long long ll;

int n,a[N],tong[N];

ll ans=1e18,x,y,s[N],ss[N];

int main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),tong[a[i]]++;
	ll lim=2e6+1;
	for(ll i=1;i<=lim;i++)
		s[i]=s[i-1]+tong[i];
	for(ll i=1;i<=lim;i++)
		ss[i]=ss[i-1]+tong[i]*i;
	for(ll i=2;i<=lim;i++)
	{
		ll cnt=0;
		for(ll j=i;j<=lim;j+=i)
		{
			ll tot=min(x/y,i-1);
			cnt+=(s[j-tot-1]-s[j-i])*x+((s[j]-s[j-tot-1])*j-(ss[j]-ss[j-tot-1]))*y;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}