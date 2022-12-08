#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1,I=1e9;
int n,k,a[N],l,r,s[N],p;
int C(int x)
{
	p=I;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)
			s[i]=s[i-1]-1;
		else
			s[i]=s[i-1]+1;
		if(i>=k)
			p=min(p,s[i-k]);
		if(s[i]-p>0)
			return 1;
	}
	return 0;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	l=1,r=n;
	while(l<r)
		if(C((l+r+1)/2))
			l=(l+r+1)/2;
		else
			r=(l+r-1)/2;
	cout<<l;
	return 0;
}