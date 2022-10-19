#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define N 1010
using namespace std;
ll n,m,nxt[N],val[N],deg[N];
vector<pair<pair<ll,ll>,ll> > ans;
int main(){
	ll x,y,z,i;
	memset(nxt,-1,sizeof(nxt));
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		nxt[x]=y;
		val[x]=z;
		deg[y]++;
	}
	for(i=0;i<n;i++)
	{
		if(deg[i]==0&&nxt[i]!=-1)
		{
			x=i;
			z=1e16;
			while(nxt[x]!=-1)
			{
				z=min(z,val[x]);
				x=nxt[x];
			}
			ans.push_back(make_pair(make_pair(i+1,x+1),z));
		}
	}
	sort(ans.begin(),ans.end());
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld %lld\n",ans[i].F.F,ans[i].F.S,ans[i].S);
	}
	return 0;
}