#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];

int soln = 0;

int dfs(int u, int pp){
    vector<int> ga;
    for(auto x : T[u]){
        if(x==pp) continue;
        ga.push_back(dfs(x,u));
    }
    sort(ga.begin(), ga.end());
    for(auto &x : ga) x ++ ;
    if(ga.empty()) return 0;
    if(ga.size() > 1){
        if(u == 1){
            soln = max({soln,ga.back(),ga[ga.size() - 2] + 1});
        }
        else{
            soln = max({soln,ga.back() + 1});
        }
    }
    soln = max(soln, ga[0]);
    return ga[0];
}

void solve(){
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
    }
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    soln = 0;
    dfs(1,-1);
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}