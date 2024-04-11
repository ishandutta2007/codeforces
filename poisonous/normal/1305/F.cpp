#include<bits/stdc++.h>
using namespace std;
long long num[200010],now[500010],p[1000010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	long long mn=max(1ll,num[1]-200002),mx=num[1]+200002;
	for(long long i=mn;i<=mx;i++)
		now[i-mn]=i;
	int ans=n;
	for(int j=2;j<=1000000;j++)
	{
		if(p[j])
			continue;
		for(int k=j+j;k<=1000000;k+=j)
			p[k]=1;
		for(long long k=mn/j*j;k<=mx;k+=j)
			if(k>=mn)
				while(now[k-mn]%j==0)
					now[k-mn]/=j;
		//cout<<j<<endl;
		int nans=0;
		for(int i=1;i<=n;i++)
		{
			if(num[i]<j)
				nans+=j-num[i];
			else
				nans+=min(num[i]%j,j-num[i]%j);
			if(nans>=ans)
				break;
		}
		ans=min(ans,nans);
	}
	for(long long k=mn;k<=mx;k++)
	{
		//cout<<now[k]<<endl;
		if(now[k-mn]==1)
			continue;
		long long nans=0;
		for(int i=1;i<=n;i++)
		{
			if(num[i]<now[k-mn])
				nans+=now[k-mn]-num[i];
			else
				nans+=min(num[i]%now[k-mn],now[k-mn]-num[i]%now[k-mn]);
			if(nans>=(long long)ans)
				break;
		}
		ans=min((long long)ans,nans);
	}
	cout<<ans<<endl;
}