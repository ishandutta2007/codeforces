#pragma GCC optimize(2)
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
ll n;
vector<ll> v;
int main(){
	ll t,x,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		v.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			v.push_back(x);
		}
		for(i=0;i<v.size();i++)
		{
			for(j=0;j<30;j++)
			{
				if(j==29||abs(v[i]-((ll)1<<j))<abs(v[i]-((ll)1<<(j+1))))
				{
					printf("%lld ",((ll)1<<j));
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}