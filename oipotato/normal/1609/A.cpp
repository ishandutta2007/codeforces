#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[20];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		int cnt=0;
		rep(i,n)
		{
			scanf("%d",&a[i]);
			for(;a[i]%2==0;cnt++,a[i]/=2);
		}
		sort(a+1,a+n+1);
		LL ans=0;
		rep(i,n-1)ans+=a[i];
		ans+=((LL)a[n])<<cnt;
		printf("%lld\n",ans);
	}
    return 0;
}