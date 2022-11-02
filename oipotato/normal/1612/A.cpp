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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if((x+y)&1)puts("-1 -1");
		else if(x>y)printf("%d %d\n",(x+y)>>1,0);
		else printf("%d %d\n",0,(x+y)>>1);
	}
    return 0;
}