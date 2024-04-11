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
int ans[1010];
int main()
{
	int now=1;
	rep(i,1000)
	{
		for(;now%10==3||now%3==0;now++);
		ans[i]=now++;
	}
	int T;
	for(scanf("%d",&T);T--;){int x;scanf("%d",&x);printf("%d\n",ans[x]);}
    return 0;
}