#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int l[MAXN],r[MAXN],e[MAXN<<1];
struct DSU
{
    int fa[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    int merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return 0;
        return fa[x]=y,1;
    }
}dsu;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        e[l[i]]=i,e[r[i]]=-i;
    }
    int edge=0;
    dsu.init(n);
    set<pair<int,int> > st;
    for(int i=1;i<=2*n;i++)
    {
        int u=abs(e[i]);
        if(e[i]>0)st.insert({l[u],u});
        else
        {
            st.erase({l[u],u});
            for(auto itr=st.lower_bound({l[u],u});itr!=st.end();itr++)
                if((++edge)==n || !dsu.merge(u,itr->second))
                    return 0*printf("NO\n");
        }
    }
     return 0*printf("%s\n",(edge==n-1 ? "YES" : "NO"));
}