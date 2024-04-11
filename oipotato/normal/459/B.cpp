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
int n,a[200010];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[1]==a[n]){printf("%d %lld\n",0,(LL)n*(n-1)/2);return 0;}
	printf("%d ",a[n]-a[1]);
	int l=1,r=n;
	for(;a[l]==a[1];l++);
	for(;a[r]==a[n];r--);
	printf("%lld\n",(LL)(l-1)*(n-r));
    return 0;
}