//copyright qiuzx
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,l,a[N],as=0,ans=0;
vector<ll> sm,lg;
bool asc()
{
	int i;
	for(i=0;i+1<l;i++)
	{
		if(a[i+1]>a[i])
		{
			return true;
		}
	}
	return false;
}
int main(){
	ll i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>l;
		for(j=0;j<l;j++)
		{
			cin>>a[j];
		}
		if(asc())
		{
			as++;
		}
		else
		{
			sm.push_back(a[l-1]);
			lg.push_back(a[0]);
		}
	}
	if(ans==1)
	{
		ans=1;
	}
	ans+=as*as;
	//cout<<ans<<endl;
	sort(sm.begin(),sm.end());
	sort(lg.begin(),lg.end());
	for(i=0;i<sm.size();i++)
	{
		j=upper_bound(lg.begin(),lg.end(),sm[i])-lg.begin();
		ans+=(lg.size()-j)+as*2;
	}
	cout<<ans<<endl;
	return 0;
}