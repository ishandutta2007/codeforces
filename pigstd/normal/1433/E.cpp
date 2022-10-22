#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans=1;

int C(int m,int n)
{
	int p=1;
	for (int i=1;i<=n;i++)p*=i;
	for (int i=1;i<=m;i++)p/=i;
	for (int i=1;i<=n-m;i++)p/=i;
	return p;
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n/2-1;i++)ans*=i;
	ans*=ans;ans*=C(n/2,n);
	ans/=2;
	cout<<ans;
	return 0;
}