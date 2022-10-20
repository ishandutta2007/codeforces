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
ll n,xt[N],v[N],ans=0,bit[N],nm[N],sum,num;
vector<pair<ll,ll> > all;
map<ll,ll> mp;
ll bs(ll x)
{
	ll ret=0;
	while(x>0)
	{
		ret+=bit[x];
		x-=x&(-x);
	}
	return ret;
}
ll gn(ll x)
{
	ll ret=0;
	while(x>0)
	{
		ret+=nm[x];
		x-=x&(-x);
	}
	return ret;
}
void update(ll x,ll val)
{
	while(x<=n)
	{
		nm[x]++;
		bit[x]+=val;
		x+=x&(-x);
	}
	return;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.S<b.S)
	{
		return true;
	}
	if(a.S>b.S)
	{
		return false;
	}
	if(a.F<b.F)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,pos;
	memset(nm,0,sizeof(nm));
	memset(bit,0,sizeof(bit));
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&xt[i]); 
	}
	all.push_back(make_pair(-1000000000,-1000000000));
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&v[i]);
		all.push_back(make_pair(xt[i],v[i]));
	}
	sort(all.begin(),all.end(),cmp);
	for(i=1;i<all.size();i++)
	{
		mp[all[i].S]=i;
	}
	sort(all.begin(),all.end());
	for(i=1;i<all.size();i++)
	{
		ans+=all[i].F*gn(mp[all[i].S])-bs(mp[all[i].S]);
	//	cout<<gn(mp[all[i].S])<<" "<<bs(mp[all[i].S])<<endl; 
		update(mp[all[i].S],all[i].F);
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}