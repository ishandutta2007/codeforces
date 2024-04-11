#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];
int B[N];
ll P[N];

int li[N];
int ri[N];

int par[N];
int lef[N];
int rig[N];
bool que[N];

vector<int> ids[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

void unite(int u, int v){
    u=fin(u);
    v=fin(v);
    if(u==v) return;
    lef[v]=min(lef[u],lef[v]);
    rig[v]=max(rig[u],rig[v]);
    par[u]=v;
}

queue<int> segt;

void activate(int node){
    par[node] = node;

    if(node > 0){
        if(par[node - 1] != -1)
            unite(node - 1, node);
    }
    if(par[node + 1] != -1){
        unite(node + 1, node);
    }
    P[node] = 0;
    for(auto x : ids[node]){
        if(P[li[x]] == 0 && P[ri[x]] == 0 && !que[x]) {
            que[x] = true;
            segt.push(x);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> A[i];
    for(int i = 1; i <= n; i ++ ) cin >> B[i];
    for(int i = 1; i <= n; i ++ ){
        P[i] = P[i - 1];
        P[i] += A[i];
        P[i] -= B[i];
    }
    for(int i = 0 ; i <= n + 1; i ++ ){
        par[i] = -1;
        lef[i] = rig[i] = i;
        ids[i].clear();
    }
    for(int i = 1; i <= m; i ++) {
        cin >> li[i] >> ri[i];
        que[i] = false;
        li[i] -- ;
        ids[li[i]].push_back(i);
        ids[ri[i]].push_back(i);
    }
    for(int i = 0 ; i <= n; i ++ ){
        if(P[i] == 0)
            activate(i);
    }
    int id;
    int vv;
    while(!segt.empty()){
        id = segt.front();
        segt.pop();
        vv = li[id];
        while(vv <= ri[id]){
            vv = fin(vv);
            vv = rig[vv] + 1;
            if(vv > ri[id]) break;
            activate(vv);
        }
    }
    int res = 1;
    for(int i = 0 ; i <= n; i ++ ){
        if(P[i] != 0) res = 0;
    }
    if(res) cout << "Yes\n";
    else cout << "No\n";
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