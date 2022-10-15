#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[102][51],n,m,i,j,k,res=0,a,b;
string s;
vector<ll> avgs;
ll calc (ll l, ll r)
{
	return b*(r-l+1)*(upper_bound(avgs.begin(),avgs.end(),r)-lower_bound(avgs.begin(),avgs.end(),l));
}
ll solve (ll l, ll r)
{
	ll x,y;
	if (upper_bound(avgs.begin(),avgs.end(),r)-lower_bound(avgs.begin(),avgs.end(),l)==0)
	{
	return a;
	}
	else
	{
	x=calc(l,r);
	if (r-l) y=solve(l,(l+r)/2)+solve((l+r)/2+1,r); else y=100000000000000001;
	return ((x<y)?x:y);
	}
}
int main(){
	cin>>n>>k>>a>>b;
	for (i=0;i<k;i++) {cin>>j; avgs.push_back(j);}
	sort(avgs.begin(),avgs.end());
	cout<<solve(1,pow(2,n));
}
//13/27
//13/21
//26/42
//27/41