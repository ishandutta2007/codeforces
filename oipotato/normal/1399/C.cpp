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
int a[55],b[55];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=2;i<=n+n;i++)
		{
			int now=n,tans=0;
			rep(j,n)
			{
				for(;now>j&&a[now]+a[j]>i;now--);
				if(now<=j)break;
				if(a[j]+a[now]==i)tans++,now--;
			}
			ans=max(ans,tans);
		}
		printf("%d\n",ans);
	}
	return 0;
}