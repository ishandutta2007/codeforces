#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int e[MAXN],in[MAXN];
vector<int> d[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&e[i]);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        d[v].push_back(u);
        in[u]++;
    }
    queue<int> q[2];
    for(int i=0;i<n;i++)
        if(!in[i])q[e[i]].push(i);
    int res=0,now=0;
    while(!q[0].empty() || !q[1].empty())
    {
        if(q[now].empty())
        {
            res+=(now^=1);
            continue;
        }
        int u=q[now].front();
        q[now].pop();
        for(auto &v:d[u])
            if((--in[v])==0)q[e[v]].push(v);
    }
    printf("%d\n",res);
    return 0;
}