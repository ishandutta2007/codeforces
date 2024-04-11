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
const long long int N = 2e6+20,mod = 1e9+7,inf = 1e9+10,sq = 32000;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}

vector<int> out[N],s[N][2],ve,in[N];
bool vis[N],good[N],p[N];
int mark[N];
int t,n;
void dfs(int v){
    vis[v] = 1;
    for (int u : out[v]){
        if(!vis[u])
            dfs(u);
    }
    ve.pb(v);
}
void sfd(int v){
    mark[v] = t;
    if(v > n) s[t][1].pb(v);
    else s[t][0].pb(v);
    for (int u : in[v]){
        if (!mark[u])
            sfd(u);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        t = 0;
        int m;
        cin >> n >> m;
        ve.clear();
        repr(i,2*n,1){
            out[i].clear();
            in[i].clear();
            s[i][0].clear();
            s[i][1].clear();
            vis[i] = 0;
            p[i] = 0;
            good[i] = 1;
            mark[i] = 0;
        }
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            v+=n;
            out[u].pb(v);
            in[v].pb(u);
        }
        rep(i,1,n+1){
            out[i+n].pb(i);
            in[i].pb(i+n);
        }
        int x = 2*n;
        rep(i,1,x+1){
            if (!vis[i]) dfs(i);
        }
        repr(i,x-1,0){
            if (!mark[ve[i]]){
                t++;
                sfd(ve[i]);
            }
        }
        if (t == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        rep(i,1,2*n+1){
            if (!good[mark[i]]) continue;
            for(int u : out[i]){
                if (mark[i] != mark[u]){
                    good[mark[i]] = 0;
                    break;
                }
            }
        }
        int g = 0;
        rep(i,1,t+1){
            if (good[i]){
                g = i;
                break;
            }
        }
        cout << s[g][0].size() << ' ' << n-s[g][0].size() << endl;
        for (int u : s[g][0]){
            cout << u <<  ' ';
            p[u] = 1;
        }
        cout << endl;
        rep(i,1,n+1) if (!p[i]) cout << i << ' ';
        cout << endl;

    }
    return 0;
}