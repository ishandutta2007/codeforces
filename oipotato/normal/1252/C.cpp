#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>>g[110];
int ans,n;
void dfs(int p,int fa,int dep)
{
    ans=max(ans,dep);
    for(auto i:g[p])if(i.first!=fa)dfs(i.first,p,dep+i.second);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);x++;y++;
        g[x].push_back(make_pair(y,z));g[y].push_back(make_pair(x,z));
    }
    dfs(1,0,0);
    printf("%d\n",ans);
    return 0;
}