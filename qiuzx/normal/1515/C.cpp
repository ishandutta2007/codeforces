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
ll n,m,x,h[N],ans[N],sum[N];
vector<pair<ll,ll> > a;
priority_queue<pair<ll,ll> > pq;
int main(){
	ll T,i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&x);
		a.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
			a.push_back(make_pair(h[i],i));
		}
		sort(a.begin(),a.end());
		while(!pq.empty())
		{
			pq.pop();
		}
		for(i=0;i<m;i++)
		{
			sum[i]=0;
			pq.push(make_pair(0,i));
		}
		for(i=a.size()-1;i>=0;i--)
		{
			x=-pq.top().F;
			y=pq.top().S;
			pq.pop();
			ans[a[i].S]=y;
			x+=a[i].F;
			sum[y]+=a[i].F;
			pq.push(make_pair(-x,y));
		}
		puts("YES");
		for(i=0;i<n;i++)
		{
			printf("%lld ",ans[i]+1);
		}
		puts("");
	}
	return 0;
}