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
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		long long sum=0,ans=0;
		for(int i=n;i;i--)
		if(a[i]>0)
		{
			long long tmp=min(0ll+a[i],sum);
			sum-=tmp;a[i]-=tmp;
			ans+=a[i];
		}
		else sum-=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}