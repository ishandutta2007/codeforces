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
int n,a[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		rep(i,n/2)printf("%d %d\n",a[i+1],a[1]);
	}
    return 0;
}