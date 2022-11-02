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
		int n,a[200010];scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int m,sum=0;scanf("%d",&m);
		rep(i,m){int x;scanf("%d",&x);sum=(sum+x)%n;}
		printf("%d\n",a[sum+1]);
	}
    return 0;
}