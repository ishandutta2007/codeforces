#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int maxn=100005;
const int K=300;
int n,m,nn,Q;
map<pair<int,int>,int> mm;
set<pair<int,int> > st;
int p[maxn*4],x[maxn],y[maxn],c[maxn],id[maxn],cnt;
int find(int x)
{
    return x==p[x]?x:p[x]=find(p[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",x+i,y+i,c+i);
        st.insert(mp(x[i],c[i]));
        st.insert(mp(y[i],c[i]));
    }
    for(set<pair<int,int> >::iterator it=st.begin();it!=st.end();it++)
        mm[*it]=nn++;
    for(int i=0;i<nn;i++)
        p[i]=i;
    for(int i=0;i<m;i++)
        p[find(mm[mp(x[i],c[i])])]=find(mm[mp(y[i],c[i])]);
    set<int>h[maxn];
    map<int,bitset<300> > g[maxn];
    for(int i=0;i<nn;i++)
        if(p[i]==i)
            id[i]=cnt++;
    for(set<pair<int,int> >::iterator it=st.begin();it!=st.end();it++)
        h[it->first].insert(id[find(mm[*it])]);
    for(int i=1;i<=n;i++)
        for(set<int>::iterator it=h[i].begin();it!=h[i].end();it++)
        {
            int x=*it/K,y=*it%K;
            g[i][x].set(y);
        }
    scanf("%d",&Q);
    while(Q--)
    {
        int x,y,ans=0;
        scanf("%d%d",&x,&y);
        if(h[x].size()>h[y].size())
            swap(x,y);
        for(map<int,bitset<300> >::iterator it=g[x].begin();it!=g[x].end();it++)
        {
            int num=it->first;
            if(g[y].find(num)==g[y].end())
                continue;
            ans+=(g[x][num]&g[y][num]).count();
        }
        printf("%d\n",ans);
    }
    return 0;
}