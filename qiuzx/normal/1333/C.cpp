#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],pos[N],sum[N],ans=0;
map<ll,ll> mp;
int main(){
	ll i,cnt=0,mx;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			sum[i]=a[i];
		}
		else
		{
			sum[i]=sum[i-1]+a[i];
		}
		if(mp[sum[i]]==0)
		{
			mp[sum[i]]=++cnt;
		}
	}
	if(mp[0]==0)
	{
		mp[0]=++cnt;
	}
	memset(pos,-1,sizeof(pos));
	pos[mp[0]]=0;
	mx=-1;
	for(i=0;i<n;i++)
	{
		mx=max(mx,pos[mp[sum[i]]]);
		ans+=i-mx;
		pos[mp[sum[i]]]=i+1;
	}
	cout<<ans<<endl;
	return 0;
}