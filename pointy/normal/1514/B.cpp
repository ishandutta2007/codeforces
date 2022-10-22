#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ll n,k,ans=1;
		cin >> n >> k;
		for (int i=1;i<=k;i++) ans=(ans*n)%mod;
		printf("%d\n",ans);
	}
	return 0;
}