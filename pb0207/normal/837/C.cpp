#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

int n,a,b;

int x[N],y[N],ans;

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if((b-y[i]>=y[j]&&x[i]<=a&&x[j]<=a)||(a-x[i]>=x[j]&&y[i]<=b&&y[j]<=b))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			if((b-x[i]>=y[j]&&y[i]<=a&&x[j]<=a)||(a-y[i]>=x[j]&&x[i]<=b&&y[j]<=b))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			if((b-y[i]>=x[j]&&x[i]<=a&&y[j]<=a)||(a-x[i]>=y[j]&&y[i]<=b&&x[j]<=b))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			if((b-x[i]>=x[j]&&y[i]<=a&&y[j]<=a)||(a-y[i]>=y[j]&&x[j]<=b&&x[i]<=b))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
		}
	cout<<ans;
}