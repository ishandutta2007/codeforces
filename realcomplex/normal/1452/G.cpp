#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
int di[N];
vector<int> T[N];
int soln[N];

int sub[N];
bool shit[N];

void dfs(int u, int pp){
    sub[u]=1;
    for(auto x : T[u]){
        if(x==pp || shit[x]) continue;
        dfs(x,u);
        sub[u]+=sub[x];
    }
}

int ff[N];
int dep[N];

vector<int> ord;

int lim;

void dfs1(int u, int pp){
    if(di[u]-1>=dep[u]){
        int cc = min(lim,di[u]-1-dep[u]);
        ff[cc]=max(ff[cc],di[u]);
    }
    ord.push_back(u);
    for(auto x : T[u]){
        if(x==pp || shit[x]) continue;
        dep[x]=dep[u]+1;
        dfs1(x,u);
    }
}

void cut(int u){
    dep[u]=0;
    dfs(u,-1);
    int sz = sub[u];
    bool ok = true;
    int pi = -1;
    while(ok){
        ok=false;
        for(auto x : T[u]){
            if(x==pi || shit[x]) continue;
            if(sub[x]>sz/2){
                pi=u;
                u=x;
                ok=true;
                break;
            }
        }
    }
    lim = sz + 1;
    for(int y = 0; y <= sz + 1; y ++ ){
        ff[y]=0;
    }
    dep[u]=0;
    ord.clear();
    dfs1(u,-1);
    for(int y = sz; y >= 0 ; y -- ){
        ff[y]=max(ff[y],ff[y+1]);
    }
    for(auto q : ord){
        soln[q]=max(soln[q],ff[dep[q]]);
    }
    shit[u]=true;
    for(auto x : T[u]){
        if(shit[x]) continue;
        cut(x);
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
    for(int i = 1; i <= n; i ++ ){
        di[i]=-1;
    }
    int k;
    cin >> k;
    int id;
    queue<int> bi;
    for(int i = 1; i <= k ; i ++ ){
        cin >> id;
        di[id]=0;
        bi.push(id);
    }
    while(!bi.empty()){
        id=bi.front();
        bi.pop();
        for(auto x : T[id]){
            if(di[x]==-1){
                di[x]=di[id]+1;
                bi.push(x);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        soln[i]=di[i];
    }
    cut(1);
    for(int i = 1; i <= n; i ++ ){
        cout << soln[i] << " ";
    }
    cout << "\n";
    return 0;
}