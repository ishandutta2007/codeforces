#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4;
int t,n;
double a[N],c,x,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		A=1e9;
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				x=(a[j]-a[i])/(j-i),c=0;
				for(int k=1;k<=n;k++)
					c+=(a[i]+x*(k-i)!=a[k]);
				A=min(A,c);
			}
		cout<<A<<'\n';
	}
}