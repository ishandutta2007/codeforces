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
vector<int>g[5];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		g[x].pb(i);
	}
	int cnt=min(g[1].size(),min(g[2].size(),g[3].size()));
	printf("%d\n",cnt);
	rep(i,cnt)printf("%d %d %d\n",g[1][i-1],g[2][i-1],g[3][i-1]);
    return 0;
}