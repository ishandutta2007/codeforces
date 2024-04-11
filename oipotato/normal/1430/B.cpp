#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
int a[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		LL ans=a[n]+a[n-1];
		reverse(a+1,a+n-1);
		for(int i=1;i<n-1&&i<k;i++)ans+=a[i];
		printf("%lld\n",ans);
	}
    return 0;
}