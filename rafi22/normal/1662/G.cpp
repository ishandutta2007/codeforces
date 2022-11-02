#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=1000007;

vector<int>G[N];
int s[N];
int ile[N];
bool is[N];
int need[N];

void dfs(int v,int o)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        s[v]+=s[u];
    }
}
ll ans;
void dfs1(int v,int o,int h)
{
    ans+=h;
    s[v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs1(u,v,h+1);
        s[v]+=s[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,p;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>p;
        G[p].pb(i);
        G[i].pb(p);
    }
    dfs(1,0);
    int c=1;
    while(true)
    {
        int nx=-1;
        for(auto u:G[c])
        {
            if(s[u]>n/2&&s[u]<=s[c]) nx=u;
        }
        if(nx==-1) break;
        c=nx;
    }
    dfs1(c,0,1);
    for(auto u:G[c]) ile[s[u]]++;
    int s=0;
    is[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(ile[i]==0) continue;
        s+=ile[i]*i;
        for(int j=0;j<=min(s,n/2);j++)
        {
            if(is[j]) need[j]=0;
            else if(j-i>=0) need[j]=need[j-i]+1;
            else need[j]=inf;
        }
        for(int j=0;j<=min(s,n/2);j++) if(need[j]<=ile[i]) is[j]=1;
    }
    ll x;
    for(int j=0;j<=n/2;j++) if(is[j]) x=j;
    ans+=x*(n-x-1);
    cout<<ans;
    return 0;
}