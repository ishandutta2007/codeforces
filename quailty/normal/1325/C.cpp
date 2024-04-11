#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
vector<int> e[MAXN];
int res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(i);
        e[v].push_back(i);
    }
    memset(res,-1,sizeof(res));
    int now=0;
    for(int i=1;i<=n;i++)
        if(e[i].size()==1)
            if(res[e[i][0]]<0)
                res[e[i][0]]=now++;
    for(int i=1;i<=n;i++)
        for(auto &t:e[i])
            if(res[t]<0)
                res[t]=now++;
    for(int i=1;i<n;i++)
        printf("%d\n",res[i]);
    return 0;
}