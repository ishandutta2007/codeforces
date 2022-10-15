
// Problem : E. Quarrel
// Contest : Codeforces - Codeforces Beta Round #29 (Div. 2, Codeforces format)
// URL : https://codeforces.com/problemset/problem/29/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 505, INF = 1e9+7;
int dis[N][N];
int prvx[N][N], prvy[N][N];
 
vector<int> adj[N];
 
int main() {
	fio;
 
    int n, m;
    cin>>n>>m;
 
    for (int i=1; i<=m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            dis[i][j] = INF;
 
    dis[1][n] = 0;
    queue<int> q;
    q.push(1);
    q.push(n);
 
    while (q.size()) {
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
 
        for (int x: adj[u])
            for (int y: adj[v])
                if (dis[x][y] == INF && x!=y) {
                    dis[x][y] = 1 + dis[u][v];
                    q.push(x);
                    q.push(y);
                    prvx[x][y] = u;
                    prvy[x][y] = v;
                }
        if (dis[n][1] < INF)    break;
    }
 
    if (dis[n][1] == INF)   cout<<-1<<endl;
    else {
        cout<<dis[n][1]<<endl;
 
        int ca = n, cb = 1;
        vector<int> ra, rb;
 
        while (ca!=1 || cb!=n) {
            ra.push_back(ca);
            rb.push_back(cb);
            int na = prvx[ca][cb];
            int nb = prvy[ca][cb];
            ca = na;
            cb = nb;
            assert(ca && cb);
        }
        ra.push_back(1);
        rb.push_back(n);
 
        reverse(ra.begin(), ra.end());
        reverse(rb.begin(), rb.end());
 
        for (int x: ra) cout<<x<<" "; cout<<endl;
        for (int x: rb) cout<<x<<" "; cout<<endl;
    }
}