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
using namespace std;
string s;
string gs(ll x)
{
	string ret=s.substr(x-1);
	ll i;
	if((s.size()-x)%2!=0)
	{
		for(i=0;i+1<x;i++)
		{
			ret+=s[i];
		}
	}
	else
	{
		for(i=x-2;i>=0;i--)
		{
			ret+=s[i];
		}
	}
	return ret;
}
int main(){
	ll t,n,i;
	vector<pair<string,ll> > vp;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		vp.clear();
		for(i=1;i<=n;i++)
		{
			vp.push_back(make_pair(gs(i),i));
		}
		sort(vp.begin(),vp.end());
		cout<<vp[0].F<<endl<<vp[0].S<<endl;
	}
	return 0;
}