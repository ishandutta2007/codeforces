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
	int n;scanf("%d",&n);
	bool flag=0;int now=1;
	LL ans=0;
	rep(i,n)
	{
		int x;scanf("%d",&x);
		ans+=abs(abs(x)-1);
		if(x<0)now*=-1;
		if(x==0)flag=1;
	}
	printf("%lld\n",ans+2*(!flag&&now==-1));
    return 0;
}