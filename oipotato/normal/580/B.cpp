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
pair<int,int>a[100010];
LL s[100010];
int main()
{
	int n,d;scanf("%d%d",&n,&d);
	rep(i,n)scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	rep(i,n)s[i]=s[i-1]+a[i].second;
	int now=1;
	LL ans=0;
	rep(i,n)
	{
		for(;now<=n&&a[now].first-a[i].first<d;now++);
		ans=max(ans,s[now-1]-s[i-1]);
	}
	printf("%lld\n",ans);
    return 0;
}