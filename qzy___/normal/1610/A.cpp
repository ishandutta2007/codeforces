#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
		if(n==1&&m==1)
			cout<<0<<'\n';
		else if(n==1||m==1)
			cout<<1<<'\n';
		else
			cout<<2<<'\n';
	return 0;
}