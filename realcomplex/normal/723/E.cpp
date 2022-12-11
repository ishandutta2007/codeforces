#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 205;
vector<pii> T[N];
bool use[N * N];

vector<int> t;
bool vis[N];
void dfs(int node){
    if(vis[node])
        return;
    vis[node] = true;
    if(T[node].size() & 1) t.push_back(node);
    for(auto x : T[node])
        dfs(x.fi);
}
set<pii> added;

void hlz(int node){
    vector<int> curp, circ;
    curp.push_back(node);
    int cd;
    while(!curp.empty()){
        cd = curp.back();
        vis[cd] = true;
        while(!T[cd].empty() && use[T[cd].back().se] == true)
            T[cd].pop_back();
        if(!T[cd].empty()){
            use[T[cd].back().se] = true;
            curp.push_back(T[cd].back().fi);
            T[cd].pop_back();
        }
        else{
            circ.push_back(curp.back());
            curp.pop_back();
        }
    }
    reverse(circ.begin(), circ.end());
    for(int i = 1; i < circ.size(); i ++ ){
        if(added.count(mp(circ[i-1], circ[i]))){
            added.erase(mp(circ[i-1], circ[i]));
            added.erase(mp(circ[i], circ[i-1]));
        }
        else cout << circ[i - 1] << " " << circ[i] << "\n";
    }
}

void Query(){
    for(int i = 0 ; i < N ; i ++ ){
        T[i].clear();
        vis[i] = false;
    }
    for(int i = 0 ; i < N * N;i ++ )
        use[i] = false;
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(mp(v, i));
        T[v].push_back(mp(u, i));
    }
    int cnt = 0;
    for(int i = 1;  i <= n; i ++ ){
        cnt += 1 - (T[i].size() % 2);
    }
    cout << cnt << "\n";
    for(int i = 1; i <= n; i ++ ){
        if(!vis[i]){
            t.clear();
            dfs(i);
            for(int i = 1; i < t.size(); i += 2){
                T[t[i - 1]].push_back(mp(t[i], m));
                T[t[i]].push_back(mp(t[i - 1], m));
                added.insert(mp(t[i], t[i-1]));
                added.insert(mp(t[i-1], t[i]));
                ++ m;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ) vis[i] = false;
    for(int i = 1; i <= n; i ++ ){
        if(!vis[i]){
            hlz(i);
        }
    }
}

int main(){
    fastIO;
    int test_cases;
    cin >> test_cases;
    while(test_cases -- ) Query();
    return 0;
}