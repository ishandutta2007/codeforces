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
#define N 200010
using namespace std;
ll t,n,ex[N],ans;
int main(){
	ll i,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ex[i]);
		}
		ans=0;
		sort(ex,ex+n);
		for(i=0;i<n;)
		{
			for(j=i+ex[i]-1;j<n;j++)
			{
				if(ex[j]<=j-i+1)
				{
					break;
				}
			}
			if(j<n||ex[n-1]<=j-i)
			{
				ans++;
			}
			i=j+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}