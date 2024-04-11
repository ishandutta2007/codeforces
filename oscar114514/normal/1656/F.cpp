#include<bits/stdc++.h>
using namespace std;
long long a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		long long minn=a[1],maxx=a[n];
		if(sum+(n-2)*minn>0)
		{
			
			cout<<"INF\n";
			continue;
		}
		if(sum+(n-2)*maxx<0)
		{
			
			cout<<"INF\n";
			continue;
		}
		//<=0 sum+(<=0 cnt*t) *(max+t)
		long long neg=0,pos=sum;
		long long ans=-9e18;
		for(int i=1;i<=n;i++)
		{
			long long t=-a[i];
			ans=max(ans,(neg+(i-1)*t)*(maxx+t)+(pos+(n-i+1)*t)*(minn+t)-(maxx+t)*(minn+t)-(n-1)*t*t);
			pos-=a[i];
			neg+=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}