#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];

int c0 = 0, c1 = 0;

void dfs(int u, int par, int bit){
    if(bit == 0) c0 ++ ;
    else c1 ++ ;
    for(auto x : T[u]){
        if(x == par) continue;
        dfs(x, u, (bit^1));
    }

}

int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, 1, 0);
    cout << min(c0-1,c1-1) << "\n";
    return 0;
}