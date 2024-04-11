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
int n,l,a[1010];
int main()
{
	scanf("%d%d",&n,&l);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	double ans=a[1];
	rep(i,n-1)ans=max(ans,(a[i+1]-a[i])/2.);
	ans=max(ans,(double)l-a[n]);
	printf("%.10lf\n",ans);
    return 0;
}