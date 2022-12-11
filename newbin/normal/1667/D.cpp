#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
#define P pair<int,int>
vector<int> g[maxn];
map< P, vector<P> > s;
map< P, int> d;
int n;
int ty[maxn];
void st(P &x){if(x.first>x.second) swap(x.first,x.second);}
void add(P x, P y){s[x].pb(y); d[y]++;}
bool dfs(int u, int f){
    int c[2] = {0,0};
    vector<P> t[2];
    for(int v:g[u]) if(f^v) {
        if(!dfs(v,u)) return false;
        c[ty[v]]++;
        t[ty[v]].pb(P(u,v));
    }
    if(u!=1){
        if(c[0]>=c[1]) ty[u] = 1; else ty[u] = 0;
        c[ty[u]]++; t[ty[u]].pb(P(u, f));
    }
    if(c[0] > c[1] || c[1]-c[0] > 1) return false;
    fors(i,0,2) {
        for(auto &x:t[i]) st(x); sort(all(t[i]));
    }
    if(g[u].size()%2 == 0){
        fors(i,0,t[0].size()){
            add(t[0][i], t[1][i]);
            if(i+1<t[0].size()) add(t[1][i],t[0][i+1]);
        }
    }else{
        assert(t[0].size()+1==t[1].size());
        fors(i,0,t[0].size()){
            add(t[1][i], t[0][i]);
            add(t[0][i],t[1][i+1]);
        }
    }
    return true;
}
void init(){
    cin>>n; s.clear(); d.clear();
    fors(i,1,n+1) g[i].clear();
    fors(i,1,n){
        int u,v; cin>>u>>v; g[u].pb(v); g[v].pb(u);
        P t = P(u,v); st(t); d[t] = 0;
    }
}
void sol(){
    if(!dfs(1, 0)) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        queue<P> q;
        vector<P> ans;
        for(auto [x,y]:d) if(y==0) q.push(x);
        while(q.size()){
            auto t = q.front(); q.pop(); ans.pb(t);
            for(auto v:s[t]){
                if(--d[v] == 0) q.push(v);
            }
        }
        for(auto [x,y]:ans) cout<<x<<" "<<y<<endl;
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        init(); sol();
    }
    return 0;
}