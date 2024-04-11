#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
LL cal(int l,int r){return (LL)(l+r)*(r-l+1)/2;}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		LL ans=0;
		for(int i=1;i<=n/2;i++)ans+=(LL)((n+1)/2-i+1)*(n/2+1-i)+cal(n/2+1-i+1,n/2);
		printf("%lld\n",ans*4);
	}
    return 0;
}