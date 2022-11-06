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
		vector<int> a(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		stack<int> p0,p1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)p0.push(i);
		}
		for(int i=n;i>=1;i--)
		{
			if(a[i]==1)p1.push(i);
		}
		int ans=0;
		while(not p0.empty() and not p1.empty() and p0.top()>p1.top())ans++,p0.pop(),p1.pop();
		cout<<ans<<"\n";
	}
	
	return 0;
}