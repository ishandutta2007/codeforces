#include<bits/stdc++.h>
using namespace std;

const int MAXP=500005;
struct DSU
{
    int fa[MAXP];
    set<int> st[MAXP];
    void init(int n)
    {
        for(int i=0;i<n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        if(st[x].size()>st[y].size())
            swap(x,y);
        for(auto &t:st[x])
            st[y].insert(t);
        st[x].clear();
        fa[x]=y;
    }
}dsu;

const int MAXN=100005;
int cnt;
map<int,int> col[MAXN];
inline int get_id(int x,int c)
{
    if(col[x].find(c)==col[x].end())
        col[x][c]=cnt++;
    return col[x][c];
}

int main()
{
    int n,m,c,q;
    scanf("%d%d%d%d",&n,&m,&c,&q);
    dsu.init(MAXP);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        dsu.st[dsu.find(get_id(x,0))].insert(get_id(y,0));
        dsu.st[dsu.find(get_id(y,0))].insert(get_id(x,0));
        dsu.merge(get_id(x,0),get_id(y,z));
        dsu.merge(get_id(x,z),get_id(y,0));
    }
    for(int i=1;i<=q;i++)
    {
        char op[5];
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(*op=='+')
        {
            int z;
            scanf("%d",&z);
            dsu.st[dsu.find(get_id(x,0))].insert(get_id(y,0));
            dsu.st[dsu.find(get_id(y,0))].insert(get_id(x,0));
            dsu.merge(get_id(x,0),get_id(y,z));
            dsu.merge(get_id(x,z),get_id(y,0));
        }
        else
        {
            int res=(dsu.find(get_id(x,0))==dsu.find(get_id(y,0))
                  || dsu.st[dsu.find(get_id(x,0))].count(get_id(y,0)));
            printf("%s\n",(res ? "Yes" : "No"));
        }
    }
    return 0;
}