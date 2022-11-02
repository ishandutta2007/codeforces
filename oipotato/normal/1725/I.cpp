#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	long long n;
	cin>>n;
	vector<int> pa(n+5,-1);
	function<int(int)> find=[&](int x){return pa[x]>0?pa[x]=find(pa[x]):x;};
	long long ans=1,rem=2*n-2;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		int pu=find(u),pv=find(v);
		int su=-pa[pu],sv=-pa[pv];
		ans=ans*su%MOD*sv%MOD*su%MOD*sv%MOD*(rem-1)%MOD;
		pa[pu]+=pa[pv];
		pa[pv]=pu;
		rem-=2;
	}
	cout<<ans<<endl;
	return 0;
}