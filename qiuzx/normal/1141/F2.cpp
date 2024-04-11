//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1510
using namespace std;
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	return x.S<y.S;
}
vector<pair<ll,ll> > calc(vector<pair<ll,ll> > v)
{
	ll i,mxcov=-1;
	vector<pair<ll,ll> > ret;
	sort(v.begin(),v.end(),cmp);
	for(i=0;i<v.size();i++)
	{
		if(v[i].F>mxcov)
		{
			ret.push_back(v[i]);
			mxcov=v[i].S;
		}
	}
	return ret;
}
map<ll,vector<pair<ll,ll> > > mp;
ll n,a[N],ans=0;
vector<pair<ll,ll> > res;
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		ll cur=0;
		for(j=i;j<n;j++)
		{
			cur+=a[j];
			mp[cur].push_back(make_pair(i,j));
		}
	}
	for(map<ll,vector<pair<ll,ll> > >::iterator it=mp.begin();it!=mp.end();it++)
	{
		vector<pair<ll,ll> > nres=calc(it->S);
		if(ans<nres.size())
		{
			ans=nres.size();
			res=nres;
		}
	}
	printf("%lld\n",ans);
	for(i=0;i<res.size();i++)
	{
		printf("%lld %lld\n",res[i].F+1,res[i].S+1);
	}
	return 0;
}