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

int sol;
int n;

void dfs(int u, int par, int d){
    int c = 0;
    for(auto x : T[u]){
        if(x == par) continue;
        dfs(x, u, d + 1);
        c ++ ;
    }
    if(c == 0) sol = max(sol, n - (2 * d - 1));
    else if(c == 1) sol = max(sol, n - (2 * d));
}

void solve(){
    cin >> n;
    int u, v;
    for(int i = 1; i <= n; i ++ )
        T[i].clear();
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    sol = 0;
    dfs(1, -1, 1);
    cout << sol << "\n";
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