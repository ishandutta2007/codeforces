#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],c[N],g;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=0;i<31;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<31;j++)
				if(a[i]>>j&1)
					c[j]++;
		g=0;
		for(int i=0;i<31;i++)
			g=__gcd(g,c[i]);
		for(int i=1;i<=n;i++)
			if(g%i==0)
				cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}