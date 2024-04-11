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
		int mia=(int)1e9+10,mib=mia;
		rep(i,n)scanf("%d",&a[i]),mia=min(mia,a[i]);
		rep(i,n)scanf("%d",&b[i]),mib=min(mib,b[i]);
		long long ans=0;
		rep(i,n)ans+=max(a[i]-mia,b[i]-mib);
		printf("%lld\n",ans);
	}
	return 0;
}