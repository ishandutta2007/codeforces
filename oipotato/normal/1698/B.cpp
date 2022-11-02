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
typedef unsigned long long ULL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		int a[200010];rep(i,n)scanf("%d",&a[i]);
		int ans=0;
		for(int i=2;i<n;i++)if(a[i]>a[i-1]+a[i+1])ans++;
		printf("%d\n",k==1?(n-1)/2:ans);
	}
    return 0;
}