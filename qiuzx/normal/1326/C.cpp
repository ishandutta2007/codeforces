#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,k,a[N],ans1=0,ans2=1;
vector<ll> v;
int main(){
	ll i;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]+k>n)
		{
			ans1+=a[i];
			v.push_back(i);
		}
	}
	for(i=1;i<v.size();i++)
	{
		ans2=(ans2*(v[i]-v[i-1]))%mod;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}