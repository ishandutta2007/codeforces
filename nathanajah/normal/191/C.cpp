#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int n,i;
int k;
vector <int> adj[100005];
vector <int> noedge[100005];
vector <int> cd[100005];
vector <int> cedge[100005];
int parent[100005];
int lca[100005][20];
int v1,v2;
int tmp;
bool sudah[100005];
int lv[100005];
vector <int> pod;
int dari[100005];
int ke[100005];
vector <int> masuk[100005];
int bit[100005];
int now[100005];
int hasil[100005];

void upd(int x, int y)
{
    while (x<100005)
    {
        bit[x]+=y;
        x+=(x&-x);
    }
}

int ambil(int x)
{
    int ret=0;
    while (x>0)
    {
        ret+=bit[x];
        x-=(x&-x);
    }
    return ret;
}

void dfs(int x)
{
    dari[x]=pod.size();
    pod.push_back(x);
    int i;
    for (i=0;i<adj[x].size();++i)
    {
        if (!sudah[adj[x][i]])
        {
            lv[adj[x][i]]=lv[x]+1;
            cd[x].push_back(adj[x][i]);
            cedge[x].push_back(noedge[x][i]);
            parent[adj[x][i]]=x;
            sudah[adj[x][i]]=true;
            dfs(adj[x][i]);
        }
    }
    ke[x]=pod.size();
}
void lcproc()
{
    int i,j;
    for (i=1;i<=n;++i)
        for (j=0;(1<<j)<n;++j)
            lca[i][j]=-1;
    for (i=1;i<=n;++i)
        lca[i][0]=parent[i];
    for (j=1; (1<<j)<n;++j)
        for (i=1;i<=n;++i)
            if (lca[i][j-1]!=-1)
                lca[i][j]=lca[lca[i][j-1]][j-1];
}
int ambil(int a, int b)
{
    int i;
    int tmp;
    int la;
    if (lv[a]<lv[b])
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    for (la=1; 1<<la <=lv[a];++la);
    --la;
    for (i=la;i>=0;--i)
        if (lv[a]-(1<<i)>=lv[b])
            a=lca[a][i];
    if (a==b)
        return a;
    for (i=la;i>=0;--i)
        if (lca[a][i]!=-1 && lca[a][i] != lca[b][i])
        {
            a=lca[a][i];
            b=lca[b][i];
        }
    return parent[a];
}

void dfs2(int x)
{
    int i;
    for (i=0;i<masuk[x].size();++i)
        upd(dari[masuk[x][i]],1);
    for (i=0;i<cd[x].size();++i)
    {
        hasil[cedge[x][i]]=ambil(ke[cd[x][i]]-1)-ambil(dari[cd[x][i]]-1);
        dfs2(cd[x][i]);
    }
}
int main()
{
    scanf("%d",&n);
    for (i=0;i<n-1;++i)
    {
        scanf("%d %d",&v1,&v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        noedge[v1].push_back(i);
        noedge[v2].push_back(i);
    }
    pod.push_back(0);
    sudah[1]=true;
    lv[1]=0;
    dfs(1);
    lcproc();
    scanf("%d",&k);
    for (i=0;i<k;++i)
    {
        scanf("%d %d",&v1,&v2);
        tmp=ambil(v1,v2);
        if (tmp!=v1)
            masuk[tmp].push_back(v1);
        if (tmp!=v2)
            masuk[tmp].push_back(v2);
    }
    dfs2(1);
    printf("%d",hasil[0]);
    for (i=1;i<n-1;++i)
        printf(" %d",hasil[i]);
    printf("\n");
}