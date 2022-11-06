#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
map<int,int> mp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%k)mp[k-a[i]%k]++;
		}
		long long ans=-1;
		for(auto x:mp)
		{
			ans=max(ans,x.first+1ll*(x.second-1)*k);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}