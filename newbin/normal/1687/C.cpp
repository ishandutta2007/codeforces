#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
#define endl "\n"
struct Dsu{
    vector<int> fa;
    void init(int n){//[0,n-1]
        fa.resize(n);
        fors(i,0,n) fa[i] = i;
    }
    int fnd(int x) {return x==fa[x]?x:fa[x]=fnd(fa[x]);}
    void link(int x, int y){
        y = fnd(y);
        fa[x] = y;
    }
};
void sol(){
    int n, m;
    cin>>n>>m;
    vector<ll> a(n+1), b(n+1);
    fors(i,1,n+1) cin>>a[i], a[i] += a[i-1];
    fors(i,1,n+1) cin>>b[i], b[i] += b[i-1];
    vector<ll> d(n+1);
    fors(i,0,n+1) d[i] = b[i]-a[i];
    Dsu pre, nxt;
    pre.init(n+3), nxt.init(n+3);
    vector< vector<int> > h(n+1);
    while(m--){
        int x, y; cin>>x>>y; x--; 
        h[x].pb(y); h[y].pb(x);
    }
    vector<int> vis(n+1); queue<int> q;
    fors(i,0,n+1) {
        if(d[i] == 0) {
            q.push(i); vis[i] = 1;
            if(i > 0) pre.link(i, i-1);
            nxt.link(i,i+1);
        }
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for(int p:h[u]){
            if(!vis[p]) continue;
            if(p < u){
                p = pre.fnd(p);
                int x = pre.fnd(u);
                while(x != p){
                    pre.link(x, x-1);
                    nxt.link(x, x+1);
                    vis[x] = 1; q.push(x);
                    x = pre.fnd(x);
                }
            }else {
                p = nxt.fnd(p);
                int x = nxt.fnd(u);
                while(x!=p){
                    pre.link(x, x-1);
                    nxt.link(x, x+1);
                    vis[x] = 1; q.push(x);
                    x = nxt.fnd(x);
                }
            }
        }
    }
    int ans = 1;
    fors(i,1,n+1) if(!vis[i]) ans = 0;
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        sol();
    }
    return 0;
}
/*
1 
5 4
0 0 0 0 0
0 0 0 0 0
1 5
2 4
3 3
1 3

*/