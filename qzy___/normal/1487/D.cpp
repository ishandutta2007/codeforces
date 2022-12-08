#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
		cout<<(int)(sqrt(2*n-1)-1)/2<<'\n';
	return 0;
}