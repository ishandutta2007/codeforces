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
ll n,a[110],b[110],c[110];
vector<ll> ans;
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
		}
		ans.clear();
		for(i=0;i+1<n;i++)
		{
			if(ans.empty())
			{
				ans.push_back(a[i]);
			}
			else
			{
				if(a[i]==ans[i-1])
				{
					ans.push_back(b[i]);
				}
				else
				{
					ans.push_back(a[i]);
				}
			}
		}
		if(a[n-1]!=ans[0]&&a[n-1]!=ans[n-2])
		{
			ans.push_back(a[n-1]);
		}
		else if(b[n-1]!=ans[0]&&b[n-1]!=ans[n-2])
		{
			ans.push_back(b[n-1]);
		}
		else
		{
			ans.push_back(c[n-1]);
		}
		for(i=0;i<n;i++)
		{
			printf("%lld ",ans[i]);
		}
		puts("");
	}
	return 0;
}