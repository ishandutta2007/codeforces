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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int k;LL x;
		scanf("%d%lld",&k,&x);
		int l=0,r=2*k-1;
		for(;l<r-1;)
		{
			int mid=((LL)l+r)>>1;
			LL ans;
			if(mid<=k)ans=(LL)mid*(mid+1)/2;else ans=(LL)k*(k+1)/2+(LL)(mid-k)*(k-1+k-(mid-k))/2;
			if(ans<x)l=mid;else r=mid;
		}
		printf("%d\n",r);
	}
    return 0;
}