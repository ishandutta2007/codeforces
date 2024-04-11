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
vector<int>g[2010];
int n,ans;
void dfs(int p,int dep)
{
	ans=max(ans,dep);
	for(auto i:g[p])dfs(i,dep+1);
}
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);if(x==-1)x=0;g[x].pb(i);}
	dfs(0,0);
	printf("%d\n",ans);
    return 0;
}