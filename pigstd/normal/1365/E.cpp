#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=505;
int n,a[M],ans;

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],ans=max(ans,a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans=max(ans,a[i]|a[j]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans;
	return 0;
}