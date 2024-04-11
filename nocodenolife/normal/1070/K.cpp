#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int a[MAXN];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll sum=0;
	for(int i=0;i<n;i++)
		sum+=1LL*a[i];
	if(sum%k!=0)
	{
		cout<<"No\n";
		return 0;
	}
	sum/=k;
	ll csum=0;
	bool valid=true;
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		csum+=1LL*a[i];
		if(csum==sum)
		{
			csum=0;
			ans.push_back(i+1);
		}
		else if(csum>sum)
			valid=false;
	}
	if(!valid)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	cout<<ans[0]<<" ";
	for(int i=1;i<ans.size();i++)
		cout<<ans[i]-ans[i-1]<<" ";
	cout<<"\n";
	return 0;
}