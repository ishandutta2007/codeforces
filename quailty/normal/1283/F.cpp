#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
void dfs(int u,int f)
{
    for(auto &v:e[u])
    {
        if(v==f)continue;
        printf("%d %d\n",u,v);
        dfs(v,u);
    }
}
int a[MAXN],usd[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&a[i]);
    for(int u=n,i=1;u>=1 && i<n;u--)
    {
        if(a[i]==u || usd[u])continue;
        usd[u]=1;
        vector<int> path;
        path.push_back(a[i]);
        usd[a[i]]=1;
        int j=i+1;
        while(j<n && !usd[a[j]])
            path.push_back(a[j]),usd[a[j]]=1,j++;
        path.push_back(u);
        i=j;
        for(int i=0;i+1<(int)path.size();i++)
            e[path[i]].push_back(path[i+1]);
    }
    printf("%d\n",a[1]);
    dfs(a[1],0);
    return 0;
}