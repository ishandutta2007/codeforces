#include<bits/stdc++.h>
using namespace std;
int n,m,k,T;
long long a[233333],s[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1,greater<int>());
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			s[i]=a[i]+s[i-1];
//			cerr<<i<<' '<<a[i]<<' '<<s[i]<<endl;
			if(s[i]>=1ll*k*i)ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}