#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int t,n,k,a[N],u;
main()
{
	for(cin>>t;cin>>n>>k;)
	{
		u=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],u=max(u,k|a[i]);
		cout<<u<<'\n';
	}
}