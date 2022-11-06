#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		set<int> s;
		int ok=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(s.contains(a[i]-k))ok=1;
		}
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}