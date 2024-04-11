#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 100010
using namespace std;
ll n,p,k;
vector<pair<pair<ll,ll>,ll> > vt,poss;
vector<ll> kth,ans;
bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
	if(a.F.F<b.F.F)
	{
		return true;
	}
	if(a.F.F>b.F.F)
	{
		return false;
	}
	if(a.F.S<b.F.S)
	{
		return false;
	}
	if(a.F.S>b.F.S)
	{
		return true;
	}
	return false;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	ll i,a,b;
	scanf("%lld%lld%lld",&n,&p,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a,&b);
		vt.push_back(make_pair(make_pair(b,a),i));
	}
	sort(vt.begin(),vt.end(),cmp);
	for(i=p-k;i<n;i++)
	{
		poss.push_back(make_pair(make_pair(vt[i].F.S,vt[i].F.F),i));
	}
	sort(poss.begin(),poss.end());
	reverse(poss.begin(),poss.end());
	for(i=0;i<k;i++)
	{
		kth.push_back(poss[i].S);
		ans.push_back(vt[poss[i].S].S);
	}
	sort(kth.begin(),kth.end());
	if(kth.empty())
	{
		kth.push_back(n);
	}
	for(i=kth[0]-1;i>kth[0]-1-p+k;i--)
	{
		ans.push_back(vt[i].S);
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return 0;
}