#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > edge;
int n,d,k,tot;
void dfs(int u,int dep,int mxd)
{
    if(dep==mxd)return;
    for(int i=0;i<k-1-(dep==0) && tot<n;i++)
    {
        int v=++tot;
        edge.push_back({u,v});
        dfs(v,dep+1,mxd);
    }
}
int main()
{

    scanf("%d%d%d",&n,&d,&k);
    if(k==1)
    {
        if(n!=2 || d!=1)printf("NO\n");
        else printf("YES\n1 2\n");
        return 0;
    }
    if(n<=d)return 0*printf("NO\n");
    for(int i=1;i<=d;i++)
        edge.push_back({i,i+1});
    tot=d+1;
    for(int i=1;i<=d+1;i++)
        dfs(i,0,min(i-1,d+1-i));
    if(tot<n)return 0*printf("NO\n");
    printf("YES\n");
    for(auto &t:edge)
        printf("%d %d\n",t.first,t.second);
    return 0;
}