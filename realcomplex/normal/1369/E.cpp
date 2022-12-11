#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
multiset<pii> T[N];
int deg[N];
int w[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; i ++ ){
        cin >> w[i];
    }
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> u >> v;
        T[u].insert(mp(v, i));
        T[v].insert(mp(u, i));
        deg[u] ++ ;
        deg[v] ++ ;
    }
    priority_queue<pii> vl;
    for(int i = 1; i <= n; i ++ ){
        if(deg[i] > 0){
            vl.push(mp(w[i] - deg[i], i));
        }
    }
    int node;
    int nex, id;
    int val;
    vector<int> ans;
    while(!vl.empty()){
        node = vl.top().se;
        val = vl.top().fi;
        vl.pop();
        if(w[node]-deg[node] != val) continue;
        if(w[node]-deg[node]+1 < 1){
            cout << "DEAD\n";
            return 0;
        }
        if(deg[node] == 0)
            continue;
        auto it = T[node].begin();
        id = it->se;
        nex = it->fi;
        T[node].erase(it);
        T[nex].erase(mp(node, id));
        deg[node] -- ;
        deg[nex] -- ;
        ans.push_back(id);
        if(deg[node] > 0){
            vl.push(mp(w[node]-deg[node], node));
        }
        if(deg[nex] > 0){
            vl.push(mp(w[nex]-deg[nex], nex));
        }
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}