#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long s=0;
		for(int i=1;i<n;i++)
		{
			s+=max(a[i]-a[i+1],0);
		}
		cout<<s<<endl;
	}
	return 0;
}