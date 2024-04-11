#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
vector<int> e[MAXN<<1];
int x[MAXN],y[MAXN],s[MAXN<<1],c[MAXN<<1],vis[MAXN<<1];
void dfs(int u,int id)
{
    if(vis[u])return;
    s[vis[u]=id]++;
    for(auto &v:e[u])
        dfs(v,id);
}
map<int,int> mpx,mpy;
inline int getx(int x)
{
    if(!mpx[x])mpx[x]=(int)mpx.size();
    return mpx[x];
}
inline int gety(int y)
{
    if(!mpy[y])mpy[y]=(int)mpy.size();
    return mpy[y];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]=getx(x[i]),y[i]=gety(y[i]);
        e[x[i]].push_back(y[i]+n);
        e[y[i]+n].push_back(x[i]);
    }
    int t=0;
    for(int i=1;i<=2*n;i++)
        if(!vis[i])dfs(i,++t);
    for(int i=1;i<=n;i++)
        c[vis[x[i]]]++;
    int res=1;
    for(int i=1;i<=t;i++)
    {
        int now=1;
        for(int j=0;j<s[i];j++)
            now=now*2%Mod;
        res=1LL*res*(now-(c[i]<s[i])+Mod)%Mod;
    }
    printf("%d\n",res);
    return 0;
}