#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mx=-1e9,dlt=0;
		for(int i=1;i<=n;i++)
		{
			dlt=max(dlt,mx-a[i]);
			mx=max(mx,a[i]);
		}
		long long x=0;
		int ans=0;
		while(x<dlt)
		{
			ans++;
			x=x*2+1;
		}
		printf("%d\n",ans);
	}
}