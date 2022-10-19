#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int t,n,a[N],x,A,y,v;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cin>>x,A=0,y=1e9;
		for(int i=1;i<=n;i++)
		{
			a[i]-=x,v=0;
			if(y+a[i]<0)
				A++,v=1;
			y=min(a[i],y+a[i]);
			if(v)
				y=1e9;
		}
		cout<<n-A<<'\n';
	}
}