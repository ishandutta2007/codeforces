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
int n,m,a[110];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,m)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	int ans=a[n]-a[1];
	rep(i,m-n+1)ans=min(ans,a[i+n-1]-a[i]);
	printf("%d\n",ans);
    return 0;
}