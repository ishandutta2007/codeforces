#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define MOD (ll(1000000007))
#define se second
ll arr[1000001];
ll cnt[1000001];
struct cmp
{
	int operator()(const pll &a, const pll &b) const
	{
		return (a.se<b.se);
	}
};
set<pll,cmp> sett;
ll n,m,i,j,k,t,u,v,a,b,res=0,cur=0;
vector<ll> lis;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		lis.push_back(i);
		if (((i-1)%(k-1)==0)and(i>1)) u++;
		cnt[i]=cnt[i-1]+u; 
		cnt[i]%=MOD;
	}
	sort(lis.begin(),lis.end(),[](ll a, ll b)
	{
		return (arr[a]>arr[b]);
	});
	sett.insert({1,n});
	cur=cnt[n];
	res=cnt[n]*arr[lis[0]];
	res%=MOD;
//	cout<<res<<endl;
	for (i=0;i<n;i++)
	{
		u=lis[i];
		if ((i)and(arr[lis[i]]<arr[lis[i-1]]))
		{
			res-=((arr[lis[i-1]]-arr[lis[i]])*cur)%MOD;
			res+=MOD;
			res%=MOD;

		}
		auto it=sett.lower_bound({u,u});
		auto pp=(*it);
		sett.erase(pp);
		cur-=cnt[pp.se-pp.fi+1];
		cur+=MOD;
		cur%=MOD;
		if (pp.se!=u)
		{
			sett.insert({u+1,pp.se});
			cur+=cnt[pp.se-(u+1)+1];
		cur+=MOD;
		cur%=MOD;
		}
		if (pp.fi!=u)
		{
			sett.insert({pp.fi,u-1});
			cur+=cnt[(u-1)-pp.fi+1];
		cur+=MOD;
		cur%=MOD;
		}
		assert(res>=0);
		assert(cur>=0);
//		cout<<cur<<' '<<res<<endl;
	}
	cout<<res;
}