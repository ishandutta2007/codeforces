#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(2*(j-i)<n)
					cout<<1<<' ';
				else if(2*(j-i)==n)
					cout<<0<<' ';
				else
					cout<<-1<<' ';
		cout<<'\n';
	}
	return 0;
}