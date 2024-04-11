#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=3e3+20,mod = 1e9+7,inf=2e9;
const long double eps = 0.0000001;
int dist[N][N];
int n,m;
vector <int> adj[N];
void bfs(int v){
    dist[v][v] = 0;
    queue <int> q;
    q.push(v);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int w : adj[u]){
            if (dist[v][w] == -1){
                dist[v][w] = dist[v][u]+1;
                q.push(w);
            }
        }
    }
    return;
}
int main(){
    memset(dist,-1,sizeof dist);
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i,0,n){
        bfs(i);
    }
    int s1,t1,l1,s2,t2,l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--;
    t1--;
    s2--;
    t2--;
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2){
        cout << -1;
        return 0;
    }
    int ans = dist[s1][t1]+dist[s2][t2];
    rep(i,0,n){
        rep(j,0,n){
            if (dist[s1][i]+dist[j][t1]+dist[i][j] <= l1 || dist[s1][j]+dist[i][j]+dist[t1][i] <= l1){
                if (dist[s2][i]+dist[j][t2]+dist[i][j] <= l2 || dist[s2][j]+dist[i][j]+dist[t2][i] <= l2){
                    ans = min(ans,min(dist[s1][i]+dist[t1][j],dist[s1][j]+dist[t1][i])+min(dist[s2][i]+dist[j][t2],dist[s2][j]+dist[t2][i])+dist[i][j]);
                }
            }
        }
    }
    cout << m - ans << endl;
    return 0;
}