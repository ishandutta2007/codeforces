#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)3e5 + 9;
vector<int> T[N];
int op[N];
int leaf[N];
int res[N];

void dfs(int u){
    if(T[u].empty()){
        leaf[u] = 1;
        res[u] = 1;
        return;
    }
    for(auto x : T[u]){
        dfs(x);
        leaf[u] += leaf[x];
    }
    if(op[u] == 1){
        res[u] = (int)1e9;
        for(auto x : T[u])
            res[u] = min(res[u], res[x]);
    }
    else{
        for(auto x : T[u])
            res[u] += res[x];
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i =1 ; i <= n; i ++ ){
        cin >> op[i];
    }
    int f;
    for(int i = 2; i <= n; i ++ ){
        cin >> f;
        T[f].push_back(i);
    }
    dfs(1);
    int w = res[1];
    cout << leaf[1] - w + 1 << "\n";
    return 0;
}