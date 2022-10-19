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
ll n,tb[N];
int main(){
	ll i,ans;
	tb[0]=1;
	for(i=1;i<N;i++)
	{
		tb[i]=(tb[i-1]*10)%mod;
	}
	cin>>n;
	for(i=1;i<n;i++)
	{
		ans=(tb[n-1-i]*9)%mod;
		ans=(ans+((tb[n-1-i]*9)%mod))%mod;
		if(n-i>=2)
		{
			ans=(ans+((tb[n-i-2]*81)%mod*(n-1-i)))%mod;
		}
		cout<<(ans*10)%mod<<endl;
	}
	cout<<10<<endl;
	return 0;
}