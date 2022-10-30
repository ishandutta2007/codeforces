#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const ll N = 1e5+50;
ll c[N];
vector <int> adj[N];
bool check(int v,int par){
    for (int u : adj[v]){
        if (u != par){
            if (!check(u,v) || c[u] != c[v]) return 0;
        }
    }
    return 1;
}
bool root(int v){
    for (int u : adj[v]){
        if (!check(u,v)) return 0;
    }
    return 1;
}
int main(){
    //think simple!!!
    int n,a,b;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep (i,1,n+1) cin >> c[i];
    rep (i,1,n+1){
        for (int u : adj[i]){
            if (c[i] != c[u]){
                if (root(i)){
                    cout << "YES" << endl << i;
                    return 0;
                }
                if (root(u)){
                    cout <<  "YES" <<endl << u;
                    return 0;
                }
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << endl << 1;

}