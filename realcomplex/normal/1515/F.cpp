#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
ll A[N];
ll X;

int par[N];

int fin(int x){
    if(par[x]==x)return x;
    return par[x]=fin(par[x]);
}

set<pii> L;
set<pii> nx[N];

void unite(int u, int v){
    u = fin(u);
    v = fin(v);
    if(u == v) return;
    if(nx[u].size() > nx[v].size())
        swap(u, v);
    L.erase(mp(A[u], u));
    L.erase(mp(A[v], v));
    for(auto x : nx[u]){
        nx[v].insert(x);
    }
    nx[u].clear();

    par[u] = v;
    A[v] += A[u] - X;
    if(A[v] < 0){
        cout << "NO\n";
        exit(0);
    }
    L.insert(mp(A[v], v));
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m >> X;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        par[i]=i;
        L.insert(mp(A[i], i));
    }
    int u, v;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v;
        nx[u].insert(mp(v, i));
        nx[v].insert(mp(u, i));
    }
    int big;
    int nex;
    int idx;
    vector<int> ord;
    for(int g = 1; g <= n - 1; g ++ ){
        auto it = L.end();
        it -- ;
        big = it->se;
        while(!nx[big].empty()){
            nex = nx[big].begin() -> fi;
            idx = nx[big].begin() -> se;
            nx[big].erase(nx[big].begin());
            if(fin(big) == fin(nex)) {
                continue;
            }
            else{
                unite(big, nex);
                ord.push_back(idx);
                break;
            }
        }
    }
    cout << "YES\n";
    for(auto x : ord)
        cout << x << " ";
    cout << "\n";
    return 0;
}