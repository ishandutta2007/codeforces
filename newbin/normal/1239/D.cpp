#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 1e6 + 50;
int n, m;
vector<int> g[maxn];
void add(int u, int v){
    g[u].push_back(v);
}
vector<int> scc[maxn];
int scnt = 0;
int idx = 0, dfn[maxn], low[maxn];
stack<int> s;
int inq[maxn];
void tarjan(int u){
    dfn[u] = low[u] = ++idx;
    inq[u] = 1;
    s.push(u);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inq[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        ++scnt;
        while(s.top() != u){
            int v = s.top(); scc[scnt].push_back(v); s.pop();
            inq[v] = 0;
        }
        s.pop(); scc[scnt].push_back(u); inq[u] = 0;
    }return;
}
vector<int> a, b;
void init(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) g[i].clear();
    while(s.size()) s.pop();
    while(m--){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
}

void sol(){
    for(int i = 1; i <= 2*n; ++i) dfn[i] = low[i] = 0, scc[i].clear();
    idx = 0; scnt = 0;
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
    if(scnt < 2){
        cout<<"No"<<endl; return;
    }
    cout<<"Yes"<<endl;
    cout<<scc[1].size()<<" "<<n-scc[1].size()<<endl;
    for(int i = 0; i < scc[1].size(); ++i){
        printf("%d ", scc[1][i]);
    }printf("\n");
    for(int i = 2; i <= scnt; ++i){
        for(int j = 0; j < scc[i].size(); ++j){
            printf("%d ", scc[i][j]);
        }
    }printf("\n");return;
}
int main()
{
    int T; cin>>T;
    while(T--){
        init();sol();
    }
}