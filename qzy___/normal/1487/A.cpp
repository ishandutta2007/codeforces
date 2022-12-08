#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int t,n,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=n;i++)
			if(a[i]>a[1])
				A++;
		cout<<A<<'\n';
	}
	return 0;
}