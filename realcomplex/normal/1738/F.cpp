#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
int par[N];
bool vis[N];

int fin(int x){
    if(par[x]==x)return x;
    return par[x]=fin(par[x]);
}

void unite(int uu, int vv){
    uu=fin(uu);
    vv=fin(vv);
    if(uu==vv)return;
    par[uu]=vv;
}

void solve(){
    int n;
    cin >> n;
    int d;
    vector<pii> dd;
    for(int i = 1; i <= n; i ++ ){
        cin >> d;
        dd.push_back(mp(d, i));
        vis[i]=false;
        par[i]=i;
    }
    sort(dd.begin(), dd.end());
    reverse(dd.begin(), dd.end());
    for(auto x : dd){
        if(vis[x.se]) continue;
        vis[x.se]=true;
        int u;
        for(int i = 0 ;i < x.fi; i ++ ){
            cout << "? " << x.se << "\n";
            fflush(stdout);
            cin >> u;
            if(vis[u]){
                unite(u,x.se);
                break;
            }
            unite(u,x.se);
            vis[u]=true;
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i ++ ){
        cout << fin(i) << " ";
    }
    cout << "\n";
    fflush(stdout);
}

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}