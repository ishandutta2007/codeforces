//Author: ACChampionEric
//Verdict: Accepted

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)

using namespace std;
typedef long long LL;
typedef long double LF;
const int maxn=50005;
const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const LL mod=1000000007;
const double EPS=1e-10;
const int BigSize=225;
int n,m,Q,OL[maxn],youhua[maxn];
vector<int> g[maxn];
inline void addfriend(int &u,int &v)
{
    if(g[u].size()>g[v].size())
        swap(u,v);
    g[u].pb(v);
    youhua[v]+=OL[u];
}
inline void delfriend(int &u,int &v)
{
    if(g[u].size()>g[v].size())
        swap(u,v);
    g[u].pb(-v);
    youhua[v]-=OL[u];
}
inline void countonlinefriends(int &u)
{
    int ans=youhua[u];
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]<0)
            ans-=OL[-g[u][i]];
        else
            ans+=OL[g[u][i]];
    printf("%d\n",ans);
}
inline void get(int &x)
{
    x=0;
    char c;
    for(c=getchar();c>'9'||c<'0';c=getchar());
    for(;c>='0'&c<='9';c=getchar())x=x*10+c-'0';
}
inline void online(int &u)
{
    OL[u]=true;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]>0)
            youhua[g[u][i]]++;
        else
            youhua[-g[u][i]]--;
}
inline void offline(int &u)
{
    OL[u]=false;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]>0)
            youhua[g[u][i]]--;
        else
            youhua[-g[u][i]]++;
}
int main()
{
    int co;
    get(n);
    get(m);
    get(Q);
    get(co);
    for(int i=1,x;i<=co;i++)
    {
        get(x);
        online(x);
    }
    for(int i=1,x,y;i<=m;i++)
    {
        get(x);
        get(y);
        addfriend(x,y);
    }
    char op;
    int u,v;

    while(Q--)
    {
        op=getchar();
        get(u);
        if(op=='O')
            online(u);
        if(op=='F')
            offline(u);
        if(op=='A')
        {
            get(v);
            addfriend(u,v);
        }
        if(op=='D')
        {
            get(v);
            delfriend(u,v);
        }
        if(op=='C')
            countonlinefriends(u);
    }
    return 0;
}