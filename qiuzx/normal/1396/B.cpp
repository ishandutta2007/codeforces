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
using namespace std;
ll T,n;
vector<ll> a;
int main(){
	ll i,x,sum;
	scanf("%lld",&T);
	while(T--)
	{
		a.clear();
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a.push_back(x);
		}
		if(n==1)
		{
			puts("T");
			continue;
		}
		sort(a.begin(),a.end());
		for(i=0;i+1<a.size();i++)
		{
			sum+=a[i];
		}
		if(sum>=a[a.size()-1])
		{
			if((sum%2)==a[a.size()-1]%2)
			{
				puts("HL");
			}
			else
			{
				puts("T");
			}
		}
		else
		{
			puts("T");
		}
	}
	return 0;
}