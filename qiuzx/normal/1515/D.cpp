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
#define N 200010
using namespace std;
ll n,l,r,a[N],app[N][2],ans;
int main(){
	ll T,i,x;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&l,&r);
		for(i=0;i<n;i++)
		{
			app[i][0]=app[i][1]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
			if(i<l)
			{
				app[a[i]][0]++;
			}
			else
			{
				app[a[i]][1]++;
			}
		}
		ans=0;
		if(l<=r)
		{
			for(i=0;i<n;i++)
			{
				x=min(app[i][0],app[i][1]);
				app[i][1]-=x;
				app[i][0]-=x;
				ans+=app[i][0];
			}
			for(i=0;i<n;i++)
			{
				x=app[i][1]/2;
				ans+=min((r-l)/2,x);
				if(r-l>=2*x)
				{
					r-=x;
					l+=x;
				}
				else
				{
					x=(r-l)/2;
					r-=x;
					l+=x;
				}
			}
			printf("%lld\n",ans+r-l);
		}
		else
		{
			for(i=0;i<n;i++)
			{
				x=min(app[i][0],app[i][1]);
				app[i][1]-=x;
				app[i][0]-=x;
				ans+=app[i][1];
			}
			for(i=0;i<n;i++)
			{
				x=app[i][0]/2;
				ans+=min((l-r)/2,x);
				if(l-r>=2*x)
				{
					l-=x;
					r+=x;
				}
				else
				{
					x=(l-r)/2;
					l-=x;
					r+=x;
				}
			}
			printf("%lld\n",ans+l-r);
		}
	}
	return 0;
}