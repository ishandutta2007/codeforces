#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define debug(x) cerr<<#x<<" :"<<x<<"\n"
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(false), cin.tie(), cout.tie();
//#define int long long

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 9;
const int INF = 1e9 + 7;
const int mlog = 24;
const int SQ = 400;

int n = 4;

int par[mlog][maxn];
int h[maxn] = {0,1,1,1};

int u1 = 1, u2 = 2;

int getpar(int v,int l)
{
    for(int j=0;j<mlog;j++)
        if(l & (1<<j))
            v = par[j][v];

    return v;
}

int lca(int u,int v)
{
    if(h[u] < h[v])
        swap(u,v);

    u = getpar(u,h[u]-h[v]);

    if(u == v)
        return v;

    for(int j=mlog-1;j>=0;j--)
    {
        int p1 = par[j][u];
        int p2 = par[j][v];

        if(p1 != p2)
            u = p1,v = p2;
    }

    return par[0][v];
}


int dist(int v,int u) { return h[v] + h[u] - 2 * h[lca(v, u)]; }

int32_t main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int v;
        scanf("%d",&v);
        for(auto u : {n,n+1})
        {
            h[u] = h[par[0][u] = v-1 ] + 1;
            for(int i=1;i<mlog;i++)
                par[i][u] = par[i-1][par[i-1][u]];

            if(dist(u1,u2) < dist(u,u2))
                u1 = u;
            if(dist(u1,u2) < dist(u1,u))
                u2 = u;
        }

        printf("%d\n",dist(u1,u2));
        n += 2;
    }

    return 0;
}