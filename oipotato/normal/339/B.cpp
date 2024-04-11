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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int last=1;
	LL ans=0;
	rep(i,m)
	{
		int x;scanf("%d",&x);
		ans+=(x+n-last)%n;
		last=x;
	}
	printf("%lld\n",ans);
    return 0;
}