#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
map<ll,ll> m[100005];
ll v[100005];
vector<ll> adj[100005];
ll sol=0;
const int mod=1000000007;
ll gcd(ll a,ll b)
{
    ll r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void dfs(int node,int dad)
{
    for(auto x:m[dad])
    {
        ll p=gcd(x.first,v[node]);
        m[node][p]+=x.second;
    }
    m[node][v[node]]++;
    for(auto x:m[node])
    {
        sol=(sol+1LL*x.first*x.second)%mod;
    }
    for(auto x:adj[node])
    {
        if(x!=dad)
        {
            dfs(x,node);
        }
    }
}
int main ()
{

    cin.tie ( 0 )->sync_with_stdio ( 0 );
    cin.tie ( NULL );
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    cout<<sol;
}