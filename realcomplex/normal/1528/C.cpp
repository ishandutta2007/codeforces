#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
vector<int> T[N];
vector<int> E[N];

int tin[N];
int tout[N];
int tt;

int outp = 0;
void dfs0(int u){
    tt ++ ;
    tin[u] = tt;
    for(auto x : E[u]){
        dfs0(x);
    }
    tout[u] = tt;
}

set<pii> segm;

void dfs(int u){
    auto it = segm.lower_bound(mp(tin[u], -1));
    vector<pii> ins, del;
    if(it != segm.begin()){
        it -- ;
        if(it->fi <= tin[u] && it->se >= tout[u]){
            del.push_back(*it);
            segm.erase(it);
        }
    }
    ins.push_back(mp(tin[u], tout[u]));
    segm.insert(mp(tin[u], tout[u]));
    outp = max(outp, (int)segm.size());
    for(auto x : T[u]){
        dfs(x);
    }
    for(auto x : ins){
        segm.erase(x);
    }
    for(auto x : del){
        segm.insert(x);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        E[i].clear();
    }
    tt = 0;
    int u, v;
    for(int i = 2; i <= n; i ++ ){
        cin >> u;
        T[u].push_back(i);
    }
    for(int i = 2; i <= n; i ++ ){
        cin >> u;
        E[u].push_back(i);
    }
    segm.clear();
    outp = 0;
    dfs0(1);
    dfs(1);
    cout << outp << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}