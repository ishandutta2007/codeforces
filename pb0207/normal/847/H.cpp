#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+1;
ll n,a[N],b[N],c[N],b1[N],c1[N];

ll solve(ll x,ll y)
{
	return x==y?1:0;
}

int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",a+i);
	for(int i=1;i<=n;++i)b[i]=c[i]=a[i];
	for(int i=2;i<=n;++i)
	{
		if(b[i]>b[i-1])continue;
		else    b[i]=b[i-1]+1;
	}
	for(int i=n-1;i>=1;--i)
	{
		if(c[i]>c[i+1])continue;
		else    c[i]=c[i+1]+1;
	}
	for(int i=1;i<=n;++i)b1[i]=b[i]-a[i],c1[i]=c[i]-a[i];
	for(int i=1;i<=n;++i)b1[i]+=b1[i-1];
	for(int i=n;i>=1;--i)c1[i]+=c1[i+1];
	ll ans=2e18;
//	cout<<b1
	b1[0]=0;c1[n+1]=0;
	for(int i=0;i<=n;++i)
	{
		ans=min(b1[i]+c1[i+1]+solve(b[i],c[i+1]),ans);
	}
	cout<<ans;
}