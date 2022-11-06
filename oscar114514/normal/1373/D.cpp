#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333],s[233333],ss[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i%2==1)sum+=a[i];
		}
		long long tmp=0,maxx=0;
		for(int i=1;i<n;i+=2)
		{
			tmp+=a[i+1]-a[i];
			tmp=max(tmp,0ll);
			maxx=max(maxx,tmp);
		}
		tmp=0;
		for(int i=2;i<n;i+=2)
		{
			tmp+=a[i]-a[i+1];
			tmp=max(tmp,0ll);
			maxx=max(maxx,tmp);
		}
//		cerr<<sum<<' '<<maxx<<endl;
		cout<<sum+maxx<<endl;
	}
	return 0;
}