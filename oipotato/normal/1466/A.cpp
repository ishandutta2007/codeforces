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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int cnt=0,n,a[55],b[2510];scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)rep(j,i-1)b[++cnt]=a[i]-a[j];
		sort(b+1,b+cnt+1);
		printf("%d\n",unique(b+1,b+cnt+1)-b-1);
	}
    return 0;
}