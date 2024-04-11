#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define double long double
#define N 10010
using namespace std;
ll n,m,znum[N];
pair<ll,ll> msh[N];
double ans=0,res[N];
vector<pair<ll,ll> > v;
int main(){
	ll i,a,h,l,r;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&a,&h,&l,&r);
		v.push_back(make_pair(a-h,100-l));
		v.push_back(make_pair(a,10000+100-l));
		v.push_back(make_pair(a+1,100-r));
		v.push_back(make_pair(a+h+1,10000+100-r));
	}
	for(i=0;i<m;i++)
	{
		res[i]=1;
		scanf("%lld%lld",&msh[i].F,&msh[i].S);
	}
	sort(msh,msh+m);
	for(i=0;i<v.size();i++)
	{
		pair<ll,ll> p=make_pair(v[i].F,-INF);
		l=lower_bound(msh,msh+m,p)-msh;
		if(v[i].S>=10000)
		{
			v[i].S-=10000;
			if(v[i].S==0)
			{
				znum[l]--;
			}
			else
			{
				res[l]*=(double)100.0/(double)(v[i].S);
			}
		}
		else
		{
			if(v[i].S==0)
			{
				znum[l]++;
			}
			else
			{
				res[l]*=(double)v[i].S/(double)100.0;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(znum[i]==0)
		{
			ans+=res[i]*(double)msh[i].S;
		}
		znum[i+1]+=znum[i];
		res[i+1]*=res[i];
	}
	printf("%.15Lf\n",ans);
	return 0;
}