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
#define N 100010
using namespace std;
ll n,c[N],t[N];
vector<ll> dif1,dif2;
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t[i]);
	}
	for(i=1;i<n;i++)
	{
		dif1.push_back(c[i]-c[i-1]);
		dif2.push_back(t[i]-t[i-1]);
	}
	sort(dif1.begin(),dif1.end());
	sort(dif2.begin(),dif2.end());
	if(dif1==dif2&&c[0]==t[0]&&c[n-1]==t[n-1])
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}