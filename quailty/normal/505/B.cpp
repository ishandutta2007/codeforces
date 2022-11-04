#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int parent[105][105];//number, color
void Init(int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int c=1;c<=m;c++)
            parent[i][c]=i;
}
int Find(int x,int c)
{
    return parent[x][c]==x?x:parent[x][c]=Find(parent[x][c],c);
}
void Union(int a,int b,int c)
{
    a=Find(a,c);
    b=Find(b,c);
    if(a!=b)parent[a][c]=parent[b][c];
}
void Compress(int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int c=1;c<=m;c++)
            parent[i][c]=Find(i,c);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Init(n,m);
    int a,b,c;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        Union(a,b,c);
    }
    Compress(n,m);
    int q;
    scanf("%d",&q);
    int u,v,res;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&u,&v);
        int res=0;
        for(int j=1;j<=m;j++){
            if(parent[u][j]==parent[v][j])res++;
        }
        printf("%d\n",res);
    }
    return 0;
}