#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

set<pii> deg; // deg; node
unordered_set<int> F[N];

void del(int node){
    deg.erase(mp(F[node].size(), node));
    for(auto x : F[node]){
        deg.erase(mp(F[x].size(), x));
        F[x].erase(node);
        deg.insert(mp(F[x].size(), x));
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ ){
        F[i].clear();
    }
    deg.clear();
    if(k > 450){
        cout << "-1\n";
        return;
    }
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        F[u].insert(v);
        F[v].insert(u);
    }
    for(int i = 1; i <= n; i ++ ){
        deg.insert(mp(F[i].size(), i));
    }
    int node;
    int sz;
    bool valid;
    while(!deg.empty()){
        node = deg.begin()->se;
        sz = deg.begin()->fi;
        if(sz <= k - 1){
            if(sz == k - 1){
                valid = true;
                for(auto x : F[node]){
                    for(auto y : F[node]){
                        if(x < y){
                            if(!F[x].count(y)){
                                valid = false;
                                break;
                            }
                        }
                    }
                    if(!valid)
                        break;
                }
                if(valid){
                    cout << 2 << "\n";
                    cout << node << " ";
                    for(auto x : F[node])
                        cout << x << " ";
                    cout << "\n";
                    return;
                }
            }
            del(node);
        }
        else{
            cout << 1 << " " << deg.size() << "\n";
            for(auto x : deg){
                cout << x.se << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ )
        solve();
    return 0;
}