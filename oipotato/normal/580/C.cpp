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
vector<int>g[100010];
int a[100010],ans,n,m;
void dfs(int p,int fa,int now)
{
	if(now>m)return;
	if(p!=1&&g[p].size()==1)ans++;
	for(auto i:g[p])if(i!=fa)dfs(i,p,a[i]?now+1:0);
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
	dfs(1,0,a[1]);
	printf("%d\n",ans);
    return 0;
}