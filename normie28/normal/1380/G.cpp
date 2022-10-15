#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second
#define MOD (ll(998244353))
ll bow (ll a, ll x)
{
	if (!x) return 1;
	ll res=bow(a,x/2);
	res*=res;
	res%=MOD;
	if (x%2) res*=a;
	return res%MOD;
}
vector<ll> buc[500001];
ll arr[500001],presum[500001];
ll n,m,i,j,k,t,u,v,a,b,res;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,[](ll a, ll b){
		return (a>b);
	});
//	for (i=1;i<=n;i++) cout<<arr[i]<<' ';cout<<endl;
	for (i=1;i<=n;i++) presum[i]=presum[i-1]+arr[i];
	for (k=1;k<=n;k++)
	{
		ll cur=0;
		for (j=1;j<=n/k;j++) cur+=(presum[j*k]-presum[j*k-k])*(j-1);
		cur+=(presum[n]-presum[j*k-k])*(j-1);
		cur%=MOD;
//		cout<<cur<<endl;
		cur*=bow(n,MOD-2);
		cur%=MOD;
		cout<<cur<<' ';
	}
}