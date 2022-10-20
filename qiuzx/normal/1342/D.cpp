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
ll n,k,ht,c[N],num[N],sum[N];
vector<ll> v;
bool check(ll x)
{
	ll i;
	for(i=k;i>0;i--)
	{
		if(sum[i]>c[i]*x)
		{
			return false;
		}
	}
	return true;
}
void ctr(ll x)
{
	ll i,j,lo;
	vector<ll> va,fa;
	vector<pair<ll,ll> > ans[N];
	for(i=0;i<x;i++)
	{
		va.push_back(n);
		fa.push_back(0);
	}
	for(i=0;i<v.size();i++)
	{
		j=upper_bound(va.begin(),va.end(),n-c[v[i]])-va.begin();
		for(;j<va.size();j++)
		{
			if(num[v[i]]<=0)
			{
				break;
			}
			lo=min(num[v[i]],c[v[i]]-(n-va[j]));
			ans[j].push_back(make_pair(lo,v[i]));
			fa[j]+=lo;
			va[j]-=lo;
			num[v[i]]-=lo;
		}
	}
	for(i=0;i<x;i++)
	{
		printf("%lld ",fa[i]);
		for(j=0;j<ans[i].size();j++)
		{
			for(lo=0;lo<ans[i][j].F;lo++)
			{
				printf("%lld ",ans[i][j].S);
			}
		}
		puts("");
	}
	return;
}
int main(){
	ll i,l,r,mid;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&ht);
		num[ht]++;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(i=k;i>=0;i--)
	{
		if(num[i]!=0)
		{
			v.push_back(i);
		}
		sum[i]=num[i]+sum[i+1];
	}
	l=-1;
	r=N;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%lld\n",l);
	ctr(l);
	return 0;
}