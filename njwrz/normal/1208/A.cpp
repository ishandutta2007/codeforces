#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,a,b,c;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		c%=3;
		if(c==0)
		{
			cout<<a;
		}else if(c==1)
		{
			cout<<b;
		}else cout<<(a^b);
		puts("");
	}
	return 0;
}