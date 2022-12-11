#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

void answer(int x){
    cout << "! " << x << "\n";
    fflush(stdout);
    exit(0);
}
map<int, int> qr;

int ask_dist(int x){
    //if(qr.count(x))
      //  return qr[x];
    cout << "d " << x << "\n";
    fflush(stdout);
    int res ;
    cin >> res;
    if(res == 0)
        answer(x);
    //qr[x] = res;
    return res;
}

int ask_next(int x){
    cout << "s " << x << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

const int N = (int)2e5 + 9;
vector<int> T[N];
int dis[N];
int pi[N];

void dfs1(int u, int par){
    pi[u] = par;
    for(auto x : T[u]){
        if(x != par){
            dis[x]=dis[u]+1;
            dfs1(x, u);
        }
    }
}

bool use[N];

int subt[N];

void dfs2(int u, int par){
    subt[u] = 1;
    for(auto x : T[u]){
        if(use[x] || x==par)
            continue;
        dfs2(x,u);
        subt[u] += subt[x];
    }
}

int d0;

void decomp(int node){
    dfs2(node, -1);
    int sz = subt[node]/2;
    int pr = -1;
    bool ok = true;
    while(ok){
        ok = false;
        for(auto x : T[node]){
            if(use[x] || x == pr) continue;
            if(subt[x] > sz){
                pr = node;
                node = x;
                ok = true;
                break;
            }
        }
    }
    use[node] = true;
    if(d0 == ask_dist(node) + dis[node]){
        decomp(ask_next(node));
    }
    else{
        decomp(pi[node]);
    }
    
}

int main(){
    //fastIO;
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs1(1,-1);
    d0 = ask_dist(1);
    decomp(1);
    return 0;
}