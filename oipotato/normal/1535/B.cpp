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
int a[2010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int ans=0;
		rep(i,n)rep(j,i-1)if(__gcd(a[i],a[j])>1&&(a[i]&1)&&(a[j]&1))ans++;
		int cnt=n-1;
		rep(i,n)if(!(a[i]&1))ans+=cnt--;
		printf("%d\n",ans);
	}
    return 0;
}