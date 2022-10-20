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
#define N 300010
using namespace std;
ll t,n,a[N];
bool dfs(ll l,ll r,ll val)
{
	if(l==r)
	{
		if(a[l]>=val)
		{
			return true;
		}
		return false;
	}
	if(l==r-1)
	{
		if(a[l]>=val&&a[r]>=val+1||a[l]>=val+1&&a[r]>=val)
		{
			return true;
		}
		return false;
	}
	if(a[l]<val||a[r]<val)
	{
		return false;
	}
	return dfs(l+1,r-1,val+1);
}
int main(){
	ll i,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(dfs(0,n-1,0))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}