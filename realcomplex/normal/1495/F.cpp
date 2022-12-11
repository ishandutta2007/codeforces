#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int LOG = 19;
const ll inf = (ll)1e15;
int P[N];
ll A[N], B[N];
vector<int> T[N];

int tin[N];
int tout[N];

ll escape[N];
int nex[LOG][N];
ll total[LOG][N];
int par[LOG][N];
ll cost[LOG][N];

int n;

void dfs(int u, int pa){
    tin[u] = u;
    tout[u] = u;
    escape[u] = A[u];
    par[0][u] = pa;
    for(int i = 1; i < LOG; i ++ ){
        cost[i][u] = cost[i - 1][u] + cost[i - 1][par[i - 1][u]];
        par[i][u] = par[i-1][par[i-1][u]];
    }
    ll cd = 0;
    for(auto x : T[u]){
        cost[0][x] = cd + A[u];
        dfs(x, u);
        cd += escape[x];
        tout[u] = tout[x];
        escape[u] += escape[x];
    }
    nex[0][u] = min(n + 1, tout[u] + 1);
    escape[u] = min(B[u], escape[u]);
    total[0][u] = escape[u];

}

ll calc(int uu, int vv){
    // assume uu < vv
    ll res = 0;
    for(int lg = LOG - 1; lg >= 0; lg -- ){
        if(nex[lg][uu] > vv || tin[nex[lg][uu]] <= tin[vv] && tout[vv] <= tout[nex[lg][uu]]){
            continue;
        }
        res += total[lg][uu];
        uu = nex[lg][uu];
    }
    if(nex[0][uu] <= vv){
        res += total[0][uu];
        uu = nex[0][uu];
    }
    for(int lg = LOG - 1; lg >= 0; lg -- ){
        if(tin[par[lg][vv]] <= tin[uu] && tout[uu] <= tout[par[lg][vv]]){
            continue;
        }
        res += cost[lg][vv];
        vv = par[lg][vv];
    }
    if(vv > uu){
        res += cost[0][vv];
        vv = par[0][vv];
    }
    return res;
}

int main(){
    fastIO;
    int q;
    cin >> n >> q;
    P[0] = n + 2;
    for(int i = 1; i <= n; i ++ ){
        cin >> P[i];
    }
    P[n + 1] = n + 1;
    A[0] = 0;
    B[0] = inf;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> B[i];
    }
    vector<int> id;
    id.push_back(0);
    for(int i = 1; i <= n + 1; i ++ ){
        while(!id.empty() && P[id.back()] < P[i])
            id.pop_back();
        T[id.back()].push_back(i);
        id.push_back(i);

    }
    dfs(0, 0);
    for(int i = n + 1; i >= 0 ; i -- ){
        for(int j = 1; j < LOG; j ++ ){
            total[j][i] = total[j-1][i] + total[j-1][nex[j-1][i]];
            nex[j][i] = nex[j-1][nex[j-1][i]];
        }
    }
    set<int> ash;
    ash.insert(0);
    ash.insert(n + 1);
    ll answer = calc(0, n + 1);
    int node;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> node;
        if(ash.count(node)){
            auto it = ash.lower_bound(node);
            auto pv = it;
            auto nx = it;
            pv -- ;
            nx ++ ;
            answer -= calc(*pv, *it);
            answer -= calc(*it, *nx);
            answer += calc(*pv, *nx);
            ash.erase(it);
        }
        else{
            ash.insert(node);
            auto it = ash.lower_bound(node);
            auto pv = it;
            auto nx = it;
            pv -- ;
            nx ++ ;
            answer += calc(*pv, *it);
            answer += calc(*it, *nx);
            answer -= calc(*pv, *nx);
        }
        cout << answer << "\n";
    }
    return 0;
}