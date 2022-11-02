#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=100007;

struct edge
{
    int u,v,w,x,y,d;
};
edge E[2*N];

set<pair<int,int>>G[N][2];
deque<pair<int,int>>Q;

void check(int v)
{
    if(sz(G[v][0])>1) Q.pb({v,0});
    if(sz(G[v][1])>1) Q.pb({v,1});
}
void ins(int i)
{
    G[E[i].u][E[i].w].insert({E[i].v,i});
    G[E[i].v][E[i].w].insert({E[i].u,i});
}
void del(int i)
{
    G[E[i].u][E[i].w].erase({E[i].v,i});
    G[E[i].v][E[i].w].erase({E[i].u,i});
}
bool odw[N];
bool is[N];

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v][0])
    {
        if(E[u.nd].d!=0) continue;
        if(v==E[u.nd].u) E[u.nd].d=1;
        else E[u.nd].d=2;
        if(!odw[u.st]) dfs(u.st);
    }
    for(auto u:G[v][1])
    {
        if(E[u.nd].d!=0) continue;
        if(v==E[u.nd].u) E[u.nd].d=1;
        else E[u.nd].d=2;
        if(!odw[u.st]) dfs(u.st);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>E[i].u>>E[i].v>>E[i].w;
            if(E[i].w==1)
            {
                is[E[i].u]^=1;
                is[E[i].v]^=1;
            }
            E[i].w--;
            ins(i);
        }
        for(int i=1;i<=n;i++) check(i);
        int it=m;
        while(!Q.empty())
        {
            int v=Q[0].st,w=Q[0].nd;
            Q.pop_front();
            if(sz(G[v][w])<2) continue;
            int i=(*G[v][w].begin()).nd;
            del(i);
            int j=(*G[v][w].begin()).nd;
            del(j);
            it++;
            if(E[i].u!=v) E[it].u=E[i].u;
            else E[it].u=E[i].v;
            if(E[j].u!=v) E[it].v=E[j].u;
            else E[it].v=E[j].v;
            E[it].w=w;
            E[it].x=i;
            E[it].y=j;
            ins(it);
            check(E[it].u);
            check(E[it].v);
            check(v);
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i]&&sz(G[i][0])+sz(G[i][1])==1) dfs(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i]) dfs(i);
        }
        for(int i=it;i>m;i--)
        {
            if(E[i].d==1)
            {
                if(E[E[i].x].u==E[i].u) E[E[i].x].d=1;
                else E[E[i].x].d=2;
                if(E[E[i].y].u==E[i].v) E[E[i].y].d=2;
                else E[E[i].y].d=1;
            }
            else
            {
                if(E[E[i].x].u==E[i].u) E[E[i].x].d=2;
                else E[E[i].x].d=1;
                if(E[E[i].y].u==E[i].v) E[E[i].y].d=1;
                else E[E[i].y].d=2;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans+=is[i];
        cout<<ans<<endl;
        for(int i=1;i<=m;i++) cout<<E[i].d;
    }

    return 0;
}