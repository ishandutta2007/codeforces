#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int MAXA=26;
struct DSU
{
    int fa[MAXA],mi[MAXA];
    void init()
    {
        for(int i=0;i<MAXA;i++)
            fa[i]=i,mi[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        fa[x]=y,mi[y]=min(mi[x],mi[y]);
    }
}dsu;
char str[MAXN];
int solve()
{
    int n,k;
    scanf("%d%d%s",&n,&k,str);
    dsu.init();
    for(int i=0;i<n;i++)
    {
        int c=str[i]-'a';
        while(dsu.mi[dsu.find(c)]>0 && k>0)
            dsu.merge(c,c-1),c=dsu.mi[dsu.find(c)],k--;
    }
    for(int i=0;i<n;i++)
        str[i]=dsu.mi[dsu.find(str[i]-'a')]+'a';
    return 0*printf("%s\n",str);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}