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
#define N 100010
using namespace std;
int main(){
	ll T;
	cin>>T;
	while(T--)
	{
		string s;
		ll ans=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			ans=max(ans,(ll)(s[i]-'0'));
		}
		printf("%lld\n",ans);
	}
	return 0;
}