#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int s[MAXN*32][2],tot=1;
void add(int v,int u=1)
{
    for(int i=29;i>=0;i--)
    {
        int go=(v>>i&1);
        if(!s[u][go])s[u][go]=++tot;
        u=s[u][go];
    }
}
int dfs(int u=1,int d=29)
{
    if(!s[u][0] && !s[u][1])return 0;
    if(!s[u][0])return dfs(s[u][1],d-1);
    if(!s[u][1])return dfs(s[u][0],d-1);
    return (1<<d)+min(dfs(s[u][0],d-1),dfs(s[u][1],d-1));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        add(a);
    }
    printf("%d\n",dfs());
    return 0;
}