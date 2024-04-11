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
		LL n;scanf("%lld",&n);
		if(n%2050)puts("-1");
		else
		{
			n/=2050;
			int ans=0;
			for(;n;ans+=n%10,n/=10);
			printf("%d\n",ans);
		}
	}
    return 0;
}