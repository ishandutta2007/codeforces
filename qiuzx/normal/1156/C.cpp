#include <bits/stdc++.h>
using namespace std;
long long n,z,a[200010],t,ans;
int main()
{
	int i;
	cin>>n>>z;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	t=0;
	for(i=0;i<n;i++)
	{
		while(a[i]-a[t]>=z)
			t++;
		ans=max(ans,i-t+1);
	}
	cout<<min(n/2,n-ans);
	return 0;
}