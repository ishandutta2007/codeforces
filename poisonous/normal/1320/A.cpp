#include<bits/stdc++.h>
using namespace std;
map<int,long long>mp;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		mp[t-i]+=t;
	}
	long long ans=0;
	for(int i=-200010;i<=400010;i++)
		ans=max(ans,mp[i]);
	cout<<ans;
}