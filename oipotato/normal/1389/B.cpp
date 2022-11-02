#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k,z;
		scanf("%d%d%d",&n,&k,&z);
		rep(i,n)scanf("%d",&a[i]);
		int ans=a[1];
		rep(i,k)ans+=a[i+1];
		for(int i=1;i<=z;i++)
		{
			if(k>2*i)
			{
				int mx=a[1]+a[2];
				for(int j=3;j<=k-2*i+1;j++)mx=max(mx,a[j]+a[j-1]);
				int tans=i*mx;
				rep(j,k-2*i+1)tans+=a[j];
				ans=max(ans,tans);
			}
			if(k>=2*i)
			{
				int mx=a[1]+a[2];
				for(int j=3;j<=k-2*i+2;j++)mx=max(mx,a[j]+a[j-1]);
				int tans=(i-1)*mx+a[k-2*i+1];
				rep(j,k-2*i+2)tans+=a[j];
				ans=max(ans,tans);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}