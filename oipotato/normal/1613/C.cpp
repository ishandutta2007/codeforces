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
int n,a[110];
LL cal(LL k)
{
	LL res=k;
	rep(i,n-1)res+=min((LL)a[i+1],a[i]+k)-a[i];
	return res;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		LL h;
		scanf("%d%lld",&n,&h);
		rep(i,n)scanf("%d",&a[i]);
		LL l=0,r=h+1;
		for(;l<r-1;)
		{
			LL mid=(l+r)>>1;
			if(cal(mid)>=h)r=mid;else l=mid;
		}
		printf("%lld\n",r);
	}
    return 0;
}