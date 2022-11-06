#include<bits/stdc++.h>
using namespace std;
int T,n,m;
long long x[233333],k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		for(int i=2;i<=n;i++)
			ans=__gcd(ans,x[i]-x[i-1]);
		if((abs(k-x[1]))%ans==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}