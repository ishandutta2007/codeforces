#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define x first
#define y second
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
#define pb push_back
#define all(v) v.begin(),v.end()
#define EPS 1e-9
#define MOD 1000000007
#define MAX 100005
typedef pair<int,int> pii;
typedef long long ll;
#define endl "\n"
int N;
ll SUM;
vector<pii> G[MAX];
int S[MAX],U[MAX],V[MAX],W[MAX];
 
int cnt(int v,int p = -1)
{
    S[v] = 1;
    for(int i=0; i<G[v].sz; i++)
        if(G[v][i].x - p)
            S[v] += cnt(G[v][i].x,v);
    return S[v];
}
 
void dfs(int v,int p = -1)
{
    for(int i=0; i<G[v].sz; i++)
        if(G[v][i].x - p)
        {
            SUM += 2*1LL*G[v][i].y*(N-S[G[v][i].x])*S[G[v][i].x];
            dfs(G[v][i].x,v);
        }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int u,v,w;
    for(int i=1; i<N; i++)
    {
        cin>>U[i]>>V[i]>>W[i];
        G[U[i]].pb(mp(V[i],W[i]));
        G[V[i]].pb(mp(U[i],W[i]));
    }
 
    cnt(1);
    dfs(1);
 
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>v>>w;
        SUM -= 2 *1LL* (W[v] - w) *1LL* (S[U[v]]>S[V[v]]?S[V[v]]*1LL*(N-S[V[v]]):S[U[v]]*1LL*(N-S[U[v]]));
        W[v] = w;
        cout<<fixed<<setprecision(10)<<(double)SUM*(3.0/((double)N*1LL*(N-1)))<<endl;
    }
 
}