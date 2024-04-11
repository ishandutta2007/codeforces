#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

struct info{
    int idx,val;
    friend bool operator<(info u,info v){
        return u.val==v.val?u.idx<v.idx:u.val<v.val;
    }
};
set<int> rv; // remained vertices
set<int> g[maxn]; // original graph
set<int> t[maxn]; // dfs tree
set<info> d;
int deg[maxn];
int n,m;

vector<int> res;

void dfs(int u){
    int crt=0;
    while (1){
        auto iter=rv.upper_bound(crt);
        if (iter==rv.end()) break;
        int v=*iter;
        crt=v;
        if (g[u].find(v)!=g[u].end()) continue;
        rv.erase(iter);
        t[u].insert(v), t[v].insert(u);
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        g[u].insert(v), g[v].insert(u);
    }
    for (int i=1;i<=n;++i) rv.insert(i);
    while (rv.size()>0){
        int tmp=rv.size();
        int u=*(rv.begin());
        dfs(u);       
        res.push_back(tmp-rv.size());
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<" ";
    for (auto c:res) cout<<c<<" ";
}