#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N], R[N];
bool has[N];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> sol;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        R[i].clear();
        has[i]=false;
    }
    int u, v;
    for(int i = 1; i <= m; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        R[v].push_back(u);
    }
    bool keep;
    for(int i = 1; i <= n; i ++ ){
        keep=true;
        for(auto x : R[i]){
            if(has[x]){
                keep=false;
            }
        }
        if(!keep){
            has[i]=false;
            sol.push_back(i);
        }
        else{
            for(auto x : T[i]){
                has[x]=true;
            }
        }
    }
    cout << sol.size() << "\n";
    for(auto x : sol)
        cout << x << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}