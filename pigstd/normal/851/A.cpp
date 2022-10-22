#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,t;

signed main()
{
	cin>>n>>k>>t;
	if (t<k)
		cout<<t;
	else if (t>n)
		cout<<n+k-t;
	else
		cout<<k;
	return 0;
}