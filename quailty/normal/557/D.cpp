#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<int>e[100005];
int vis[100005],cnt[2];
bool bfs(int st)
{
    queue<int>q;
    vis[st]=1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cnt[vis[u]-1]++;
        for(int i=0;i<e[u].size();i++)
        {
            if(!vis[e[u][i]])
            {
                vis[e[u][i]]=3-vis[u];
                q.push(e[u][i]);
            }
            else
            {
                if(vis[e[u][i]]==vis[u])return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int maxd=0;
    for(int i=1;i<=n;i++)
    {
        maxd=max(maxd,(int)e[i].size());
    }
    if(maxd==0)
    {
        printf("3 %I64d\n",1LL*n*(n-1)*(n-2)/6);
    }
    else if(maxd==1)
    {
        printf("2 %I64d\n",1LL*m*(n-2));
    }
    else
    {
        bool odd=0;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cnt[0]=cnt[1]=0;
                if(!bfs(i))
                {
                    odd=1;
                    break;
                }
                ans+=1LL*cnt[0]*(cnt[0]-1)/2;
                ans+=1LL*cnt[1]*(cnt[1]-1)/2;
            }
        }
        if(odd)printf("0 1\n");
        else printf("1 %I64d\n",ans);
    }
    return 0;
}