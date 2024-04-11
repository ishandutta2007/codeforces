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
#define N 110
using namespace std;
ll n,k,h[N];
ll find_pos()
{
	ll i;
	for(i=0;i+1<n;i++)
	{
		if(h[i]<h[i+1])
		{
			h[i]++;
			return i;
		}
	}
	return -1;
}
int main(){
	ll t,i,p;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		for(i=0;i<k;i++)
		{
			p=find_pos();
			if(p==-1)
			{
				p--;
				break;
			}
		}
		printf("%lld\n",p+1);
	}
	return 0;
}