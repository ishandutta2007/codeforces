// LUOGU_RID: 90568392
#include <bits/stdc++.h>
#define INF 1500000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,dx[N],dy[N],ord[N],curx=0,cury=0,ans[N];
bool cmp(ll x,ll y)
{
	return (dx[x]*dx[x]+dy[x]*dy[x])>(dx[y]*dx[y]+dy[y]*dy[y]);
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
		ord[i]=i;
	}
	sort(ord,ord+n,cmp);
	ll B=min((ll)20,n);
	for(i=B;i<n;i++)
	{
		if((curx+dx[ord[i]])*(curx+dx[ord[i]])+(cury+dy[ord[i]])*(cury+dy[ord[i]])>(curx-dx[ord[i]])*(curx-dx[ord[i]])+(cury-dy[ord[i]])*(cury-dy[ord[i]]))
		{
			ans[ord[i]]=-1;
			curx-=dx[ord[i]];
			cury-=dy[ord[i]];
		}
		else
		{
			ans[ord[i]]=1;
			curx+=dx[ord[i]];
			cury+=dy[ord[i]];
		}
	}
	for(i=0;i<(1<<B);i++)
	{
		ll resx=curx,resy=cury;
		for(j=0;j<B;j++)
		{
			if(i&(1<<j))
			{
				ans[ord[j]]=1;
				resx+=dx[ord[j]];
				resy+=dy[ord[j]];
			}
			else
			{
				ans[ord[j]]=-1;
				resx-=dx[ord[j]];
				resy-=dy[ord[j]];
			}
		}
		if(resx*resx+resy*resy<=(ll)INF*INF)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}