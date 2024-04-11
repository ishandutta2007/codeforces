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
int a[1010];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m+1)scanf("%d",&a[i]);
	int ans=0;
	rep(i,m)if(__builtin_popcount(a[i]^a[m+1])<=k)ans++;
	printf("%d\n",ans);
    return 0;
}