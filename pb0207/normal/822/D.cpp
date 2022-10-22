#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N= 5e6+1;
const ll mod = 1e9+7;
const ll inf = 1e18;

ll f[N],l,r,t,anss,ans[N];

int main()
{
	cin>>t>>l>>r;
	fill(f+1,f+N,inf);
	for(ll i=1;i<N;++i)ans[i]=i*(i-1)>>1;
	for(ll i=1;i<N;++i)
	{
		f[i]=min(ans[i],f[i]);
		ll len2=2;
		for(ll j=i*2;j<N;j+=i,len2++)f[j]=min(f[j],ans[len2]*i+f[i]);
		f[i]%=mod;
	}
	ll t1=1;
	for(int i=l;i<=r;++i)
	{
		(anss+=f[i]*t1)%=mod;
		(t1*=t)%=mod;
	}
	cout<<anss;
	return 0;
}