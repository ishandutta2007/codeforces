#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
int par[N];
int sz[N];

ll outp = 0;


int fin(int u){
    while(par[u] != u) u=par[u];
    return u;
}

vector<pii> upd;

void unite(int u, int v){
    u=fin(u);
    v=fin(v);
    if(u==v) return;
    if(sz[u] > sz[v]) swap(u, v);
    par[u]=v;
    sz[v] += sz[u];
    upd.push_back(mp(u, v));
}

vector<pii> T[N];

void solve(int lef, int rig){
    if(lef == rig){
        for(auto x : T[lef]){
            outp += sz[fin(x.fi)] * 1ll * sz[fin(x.se)];
        }
        return;
    }


    int mid = (lef + rig) / 2;

    for(int i = lef; i <= mid; i ++ ){
        for(auto x : T[i]){
            unite(x.fi, x.se);
        }
    }

    solve(mid + 1, rig);


    int ui, vi;

    for(int i = lef; i <= mid ; i ++ ){
        for(auto x : T[i]){
            ui = upd.back().fi;
            vi = upd.back().se;
            upd.pop_back();
            sz[vi] -= sz[ui];
            par[ui] = ui;
        }
    }

    for(int i = mid + 1; i <= rig ; i ++ ){
        for(auto x : T[i]){
            unite(x.fi, x.se);
        }
    }


    solve(lef, mid);

    for(int i = mid + 1; i <= rig ; i ++ ){
        for(auto x : T[i]){
            ui = upd.back().fi;
            vi = upd.back().se;
            upd.pop_back();
            sz[vi] -= sz[ui];
            par[ui] = ui;
        }
    }


}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        par[i] = i;
        sz[i] = 1;
    }
    int u, v, w;
    for(int i = 1 ; i < n; i ++ ){
        cin >> u >> v >> w;
        T[w].push_back(mp(u, v));
    }
    solve(1, n);
    cout << outp << "\n";
    return 0;
}