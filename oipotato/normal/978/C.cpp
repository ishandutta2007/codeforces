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
LL a[200010];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%lld",&a[i]);
	LL sum=0;
	int now=1;
	rep(i,m)
	{
		LL x;scanf("%lld",&x);
		for(;x-sum>a[now];sum+=a[now++]);
		printf("%d %lld\n",now,x-sum);
	}
    return 0;
}