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
#define N 1010
using namespace std;
ll n,a[N],b[N];
vector<ll> tx,ty;
int main(){
	ll T,i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		tx.clear();
		ty.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a[i],&b[i]);
			tx.push_back(a[i]);
			ty.push_back(b[i]);
		}
		sort(tx.begin(),tx.end());
		sort(ty.begin(),ty.end());
		if(n%2==1)
		{
			puts("1");
			continue;
		}
		else
		{
			x=tx[n/2]-tx[n/2-1]+1;
			y=ty[n/2]-ty[n/2-1]+1;
			printf("%lld\n",x*y);
		}
	}
	return 0;
}