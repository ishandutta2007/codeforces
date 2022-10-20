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
using namespace std;
int main(){
	ll t,n,i,x,ans;
	vector<ll> a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a.clear();
		for(i=0;i<n*2;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		x=a[a.size()/2];
		ans=x-a[a.size()/2-1];
		cout<<ans<<endl;
	}
	return 0;
}