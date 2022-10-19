#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll t,n;
int main(){
	ll i,d,cnt,cnt2;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		d=0;
		for(i=2;i<=n;i<<=1)
		{
			d++;
		}
		printf("%lld\n",d);
		n=i-1-n;
		cnt=1;
		cnt2=(i>>1)-1;
		for(i=0;i<d;i++)
		{
			printf("%lld ",cnt-n/cnt2);
			cnt<<=1;
			cnt-=n/cnt2;
			n%=cnt2;
			cnt2=((cnt2+1)>>1)-1;
		}
		puts("");
	}
	return 0;
}