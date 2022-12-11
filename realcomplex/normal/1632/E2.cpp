#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;

vector<int> T[N];
int dep[N];
int mx[N];
int d0[N];
int d1[N];

void dfs(int u, int par){
    d0[u] = d1[u] = dep[u];
    mx[u] = dep[u];
    for(auto x : T[u]){
        if(x == par) continue;
        dep[x] = dep[u] + 1;
        dfs(x, u);
        mx[u] = max(mx[u], mx[x]);
        if(mx[x] > d0[u]){
            d1[u] = d0[u];
            d0[u] = mx[x];
        }
        else if(mx[x] > d1[u]){
            d1[u] = mx[x];
        }
    }
}

vector<pii> E[N];

int f[N];
int dist[N];

void solve(){
    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i <= n + 1; i ++ ){
        T[i].clear();
        E[i].clear();
        dep[i] = mx[i] = d0[i] = d1[i] = 0;
        f[i] = dist[i] = 0;
    }
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i ++ ){
        E[d0[i]].push_back(mp(i, 0));
        E[d1[i]].push_back(mp(i, 1));
    }
    int maxi = -(int)1e9;
    for(int i = n; i >= 1; i -- ){
        for(auto x : E[i]){
            dist[x.fi] += i - dep[x.fi];
            if(x.se == 1)
                maxi = max(maxi, dist[x.fi]);
        }
        f[i] = maxi;
    }
    int lef, rig;
    int mid;
    for(int x = 1; x <= n; x ++ ){
        lef = 1;
        rig = n;
        while(lef < rig){
            mid = (lef + rig) / 2;
            if((f[mid + 1] + 1) / 2 + x > mid){
                lef = mid + 1;
            }
            else{
                rig = mid;
            }
        }
        cout << lef << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}