#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+5),ans(n+5);
		vector<pair<int,int>> vec;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			vec.emplace_back(a[i-1]-a[i],i);
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<n;i++)
			ans[i+1]=vec[i].second;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<"\n";
	}
	
	return 0;
}