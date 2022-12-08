#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],b[N],p,q,l,r;
int C(int x)
{
	p=x-1,q=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=p&&b[i]>=q&&p>=0)
			p--,q++;
	return p==-1;
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		l=0,r=n;
		while(l<r)
			if(C((l+r+1)/2))
				l=(l+r+1)/2;
			else
				r=(l+r-1)/2;
		cout<<l<<'\n';
	}
	return 0;
}