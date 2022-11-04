#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],res;
void dfs(int u)
{
    int p=e[u][0],q=e[u][1],v=-1;
    if(p==e[q][0] || p==e[q][1])v=q;
    if(q==e[p][0] || q==e[p][1])v=p;
    res.push_back(v);
    if(v==1)return;
    dfs(v);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[i].push_back(a);
        e[i].push_back(b);
        sort(e[i].begin(),e[i].end());
    }
    if(n>3)
    {
        dfs(1);
        for(auto &t:res)
            printf("%d ",t);
    }
    else printf("1 2 3");
    return 0;
}