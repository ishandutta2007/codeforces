#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,s,A,y,x;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		s=1,A=y=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			while(x%2==0)
				s*=2,x/=2;
			y=max(y,x),A+=x;
		}
		cout<<A+(s-1)*y<<'\n';
	}
	return 0;
}