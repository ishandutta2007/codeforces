#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int c1=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			c1+=(a[i]==1);
		}
		sort(a+1,a+n+1);
		if(not c1)cout<<"YES"<<endl;
		else
		{
			int ok=1;
			for(int i=1;i<n;i++)
			{
				if(a[i+1]-a[i]==1)
					ok=0;
			}
			if(ok)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
	return 0;
}