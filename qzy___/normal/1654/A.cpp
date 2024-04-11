#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n]+a[n-1]<<'\n';
	}
}