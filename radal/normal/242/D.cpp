#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e5+30,inf = 1e9;
int n,m;
vector <int> adj[N],sc,ve;
int a[N],b[N];
void bfs(){
    queue <int> q;
    for (int u : sc){
        q.push(u);
        b[u]++;
    }
    while (!q.empty()){
        int v = q.front();
        ve.pb(v);
        q.pop();
        for (int u : adj[v]){
            b[u]++;
            if (a[u] == b[u]) q.push(u);
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i,1,n+1){
        cin >> a[i];
        if (!a[i]) sc.pb(i);
    }
    bfs();
    cout << ve.size() << endl;
    for (int u : ve) cout << u << ' ';
    return 0;
}