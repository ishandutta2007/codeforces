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
LL f[200010];
int a[200010],n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
		for(int i=n;i;i--)f[i]=i+a[i]<=n?f[i+a[i]]+a[i]:a[i];
		LL mx=0;rep(i,n)mx=max(mx,f[i]);
		printf("%lld\n",mx);
	}
    return 0;
}