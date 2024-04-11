#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
		if(n&1)
			cout<<(2*(k-1)/(n-1)+k-1)%n+1<<'\n';
		else
			cout<<(k-1)%n+1<<'\n';
	return 0;
}