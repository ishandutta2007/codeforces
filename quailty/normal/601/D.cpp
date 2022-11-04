#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
struct node
{
    node* nxt[26];
    int ed;
    node()
    {
        for(int i=0;i<26;i++)nxt[i]=NULL;
        ed=0;
    }
};
node* rt[MAXN];
int c[MAXN],sz[MAXN],df[MAXN];
char s[MAXN];
vector<int>e[MAXN];
void mer(node* &u,int &idu,node* v)
{
    if(v->ed && !u->ed)
    {
        u->ed=1;
        df[idu]++;
    }
    for(int i=0;i<26;i++)
    {
        if(!v->nxt[i])continue;
        if(!u->nxt[i])u->nxt[i]=new node;
        mer(u->nxt[i],idu,v->nxt[i]);
    }
    delete v;
}
void mer(int u,int v)
{
    if(sz[u]<sz[v])
    {
        swap(rt[u],rt[v]);
        swap(sz[u],sz[v]);
        df[u]=df[v];
    }
    mer(rt[u],u,rt[v]);
}
void dfs(int u,int fa)
{
    rt[u]=new node,sz[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        mer(u,v);
    }
    node* tmp=new node;
    tmp->nxt[s[u]-'a']=rt[u];
    rt[u]->ed=1;
    rt[u]=tmp,sz[u]++,df[u]++;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    scanf("%s",s+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int res=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(res<df[i]+c[i])
        {
            res=df[i]+c[i];
            cnt=0;
        }
        if(res==df[i]+c[i])cnt++;
    }
    printf("%d\n%d\n",res,cnt);
    return 0;
}