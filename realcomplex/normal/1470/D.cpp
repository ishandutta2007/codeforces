#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
set<int> T[N];
bool inq[N];
bool bad[N];

void solve(){
    int n,m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        inq[i]=false;
        bad[i]=false;
    }
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v;
        T[u].insert(v);
        T[v].insert(u);
    }
    queue<int> bb;
    bb.push(1);
    inq[1]=true;
    int node;
    int nx;
    vector<int> sol;
    while(!bb.empty()){
        node=bb.front();
        bb.pop();
        if(bad[node]){
            while(!T[node].empty()){
                auto it = T[node].begin();
                nx = *it;
                T[node].erase(it);
                if(inq[nx] || bad[nx]) continue;
                inq[nx]=true;
                bb.push(nx);
                break;
            }
            if(!T[node].empty()) bb.push(node);
        }
        else{
            sol.push_back(node);
            for(auto x : T[node]){
                if(!inq[x])
                    bb.push(x);
                inq[x]=true;
                bad[x]=true;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(!inq[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << sol.size() << "\n";
    for(auto x : sol)
        cout << x << " ";
    cout << "\n";

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