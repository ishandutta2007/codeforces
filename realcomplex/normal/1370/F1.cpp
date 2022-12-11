#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;
int dd[N][N];
vector<int> T[N];

void dfs(int u, int par, int di, int root){
    dd[root][u] = di;
    for(auto x : T[u]){
        if(x == par) continue;
        dfs(x, u, di + 1, root);
    }
}

pii query(vector<int> ask){
    cout << "? " << ask.size() << " ";
    for(auto x : ask) cout << x << " ";
    cout << "\n";
    fflush(stdout);
    pii ans;
    cin >> ans.fi >> ans.se;
    return ans;
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
    for(int i = 1; i <= n; i ++ ) dfs(i, -1, 0, i);
    pii ss;
    vector<int> qq;
    for(int i = 1; i <= n; i ++ )
        qq.push_back(i);
    ss = query(qq);
    int root = ss.fi;
    int len = ss.se;
    int l = (len+1)/2, r = len+1;
    int mid;
    bool good;
    while(l + 1 < r){
        mid = (l + r) / 2;
        vector<int> ask;
        good = true;
        for(int i = 1; i <=n ; i ++ ){
            if(dd[root][i] == mid){
                ask.push_back(i);
            }
        }
        if(ask.empty()){
            good = false;
        }
        else{
            ss = query(ask);
            if(ss.se != len){
                good = false;
            }
            else{
                good = true;
            }
        }
        if(good)
            l = mid;
        else
            r = mid;
    }
    vector<int> ask;
    for(int i = 1; i <= n; i ++ ){
        if(dd[root][i] == l)
            ask.push_back(i);
    }
    ss = query(ask);
    int v1 = ss.fi;
    ask.clear();
    for(int i = 1; i <= n; i ++ ){
        if(dd[v1][i] == len){
            ask.push_back(i);
        }
    }
    ss = query(ask);
    int v2 = ss.fi;
    cout << "! " << v1 << " " << v2 << "\n";
    fflush(stdout);
    string res;
    cin >> res;
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 0 ; t < tc; t ++ )
        solve();
    return 0;
}