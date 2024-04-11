//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define ll long long
#define N 6010
using namespace std;
ll n,lft[2][2],ans=0;
vector<pair<ll,ll> > v;
int main(){
	ll i,j,x,y;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x/=2;
		y/=2;
		x%=2;
		y%=2;
		v.push_back(make_pair(x,y));
		lft[x][y]++;
	}
	for(i=0;i<n;i++)
	{
		lft[v[i].F][v[i].S]--;
		for(j=i+1;j<n;j++)
		{
			lft[v[j].F][v[j].S]--;
			ll dif=(v[i].F^v[j].F)|(v[i].S^v[j].S);
			if(dif==0)
			{
				ans+=lft[0][0]+lft[0][1]+lft[1][0]+lft[1][1];
			}
			else
			{
				ans+=lft[v[i].F][v[i].S]+lft[v[j].F][v[j].S];
			}
		}
		for(j=i+1;j<n;j++)
		{
			lft[v[j].F][v[j].S]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}