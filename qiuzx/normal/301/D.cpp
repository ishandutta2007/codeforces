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
ll n,m,p[N],plc[N],ans[N],bit[N];
vector<ll> vt[N];
vector<pair<pair<ll,ll>,ll> > que;
void update(ll x,ll v)
{
	x++;
	while(x<N)
	{
		bit[x]+=v;
		x+=(x&(-x));
	}
	return;
}
ll query(ll x)
{
	ll ret=0;
	x++;
	while(x>0)
	{
		ret+=bit[x];
		x-=(x&(-x));
	}
	return ret;
}
int main(){
	ll i,j,k,l,r;
	scanf("%I64d%I64d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&p[i]);
		plc[p[i]]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%I64d%I64d",&l,&r);
		l--;
		r--;
		que.push_back(make_pair(make_pair(l,r),i));
	}
	sort(que.begin(),que.end());
	reverse(que.begin(),que.end());
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			l=min(plc[i],plc[j]);
			r=max(plc[i],plc[j]);
			vt[l].push_back(r);
		}
	}
	j=n;
	for(i=0;i<que.size();i++)
	{
		while(j>que[i].F.F)
		{
			j--;
			for(k=0;k<vt[j].size();k++)
			{
				update(vt[j][k],1);
			}
		}
		ans[que[i].S]=query(que[i].F.S);
	}
	for(i=0;i<que.size();i++)
	{
		printf("%I64d\n",ans[i]);
	}
	return 0;
}