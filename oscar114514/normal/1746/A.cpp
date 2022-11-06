#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		string ans="NO";
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x==1)ans="YES";
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}