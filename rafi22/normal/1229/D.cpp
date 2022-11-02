#include <bits/stdc++.h>

//#define int long long
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

const int N=200007,M=127;

vector<int>pos[M];
map<vector<int>,int>id;
vector<int>P[N];
int a[N];
int G[M][M];
bool tak[M];
vector<int>is;

void dfs(int v)
{
    is.pb(v);
    tak[v]=1;
    for(auto u:is)
    {
        if(!tak[G[v][u]]) dfs(G[v][u]);
        if(!tak[G[u][v]]) dfs(G[u][v]);
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
        int n,k;
        cin>>n>>k;
        vector<int>p(k);
        for(int i=0;i<k;i++) p[i]=i+1;
        int it=0;
        while(true)
        {
            id[p]=++it;
            if(!next_permutation(all(p))) break;
        }
        it=0;
        for(int i=0;i<k;i++) p[i]=i+1;
        while(true)
        {
            it++;
            int it1=0;
            vector<int>p1(k);
            for(int i=0;i<k;i++) p1[i]=i+1;
            while(true)
            {
                it1++;
                vector<int>y(k);
                for(int i=0;i<k;i++) y[i]=p[p1[i]-1];
                G[it][it1]=id[y];
                if(!next_permutation(all(p1))) break;
            }
            if(!next_permutation(all(p))) break;
        }
        for(int i=1;i<=n;i++)
        {
            P[i].resize(k);
            for(int j=0;j<k;j++) cin>>P[i][j];
            a[i]=id[P[i]];
        }
        for(int i=n;i>0;i--) pos[a[i]].pb(i);
        set<int>S;
        for(int i=1;i<=it;i++) if(sz(pos[i])>0) S.insert(pos[i].back());
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(tak,0,sizeof tak);
            is.clear();
            is.pb(1);
            tak[1]=1;
            int r=i-1;
            for(auto x:S)
            {
                ans+=(ll)sz(is)*(x-1-r);
                r=x-1;
                if(sz(is)==120) break;
                if(tak[a[x]]) continue;
                dfs(a[x]);
            }
            ans+=(ll)sz(is)*(n-r);
            if(sz(pos[a[i]])>0)
            {
                S.erase(i);
                pos[a[i]].pop_back();
                if(sz(pos[a[i]])>0) S.insert(pos[a[i]].back());
            }
        }
        cout<<ans;
    }

    return 0;
}