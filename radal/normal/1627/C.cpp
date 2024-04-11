#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e18,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
vector<pll> adj[N];
int ans[N];
int main(){
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        rep(i,1,n){
            int u,v;
            cin >> u >> v;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }
        bool f = 0;
        int st = -1,st2 = -1;
        rep(i,1,n+1){
            if (adj[i].size() > 2){
                f = 1;
                break;
            }
            if (adj[i].size() == 1){
                st2 = st;
                st = i;
            }
        }
        if (f){
            cout << -1 << endl;
            rep(i,1,n+1) adj[i].clear();
            continue;
        }
        int perv = 0;
        while (st != st2){
            if (adj[st][0].X != perv){
                if (f) ans[adj[st][0].Y] = 2;
                else ans[adj[st][0].Y] = 3;
                perv = st;
                st = adj[st][0].X;
                f = 1-f;
                continue;
            }
            if (f) ans[adj[st][1].Y] = 2;
            else ans[adj[st][1].Y] = 3;
            f = 1-f;
            perv = st;
            st = adj[st][1].X;
        }
        rep(i,1,n) cout << ans[i] << ' ';
        cout << endl;
        rep(i,1,n+1) adj[i].clear();
    }
}