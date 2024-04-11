#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,v[101],x,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		memset(v,0,sizeof(v)),A=0;
		for(int i=1;i<=n;i++)
			cin>>x,v[abs(x)]++;
		for(int i=1;i<=100;i++)
			A+=min(2ll,v[i]);
		cout<<A+min(1ll,v[0])<<'\n';
	}
}