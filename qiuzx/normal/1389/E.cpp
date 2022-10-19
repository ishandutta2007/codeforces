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
ll T,m,d,w,g,mn;
int main(){
	cin>>T;
	while(T--)
	{
		cin>>m>>d>>w;
		mn=min(m,d);
		d--;
		if(d==0)
		{
			puts("0");
			continue;
		}
		d%=w;
		g=__gcd(d,w);
		g=w/g;
		if(g>=mn)
		{
			puts("0");
			continue;
		}
		printf("%lld\n",((mn-g)+(mn-g)%g)*(((mn-g)-(mn-g)%g)/g+1)/2);
	}
	return 0;
}