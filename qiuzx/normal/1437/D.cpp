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
ll n,a[N],ans;
queue<pair<ll,ll> > q;
int main(){
	ll t,i,id,x,st;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]--;
		}
		ans=0;
		q.push(make_pair((ll)0,(ll)0));
		id=1;
		while(!q.empty())
		{
			x=q.front().F;
			st=q.front().S;
			ans=max(ans,st);
			q.pop();
			if(id<n)
			{
				do
				{
					q.push(make_pair(a[id],st+1));
					id++;
				}while(id<n&&a[id]>a[id-1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}