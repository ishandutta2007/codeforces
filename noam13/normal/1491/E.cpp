#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int n;
vvii g;
vii edge;
vb mark;
vi fib;

vi ind;
vi sz;
int eind = -1, who = -1;
int dfs(int cur, int i, int p=-1){
    sz[cur] = 1;
    for(auto nei:g[cur])if(nei.y!=p && !mark[nei.y]){
        sz[cur]+=dfs(nei.x, i, nei.y);
    }
    if (sz[cur]==fib[i-1] || sz[cur]==fib[i-2]){
        if (p!=-1){
            eind = p;
            who = cur;
        }
    }
    return sz[cur];
}
void solve(int cur, int i){
    if (i<=2) return ;
    eind = -1;
    dfs(cur, i);
    if (eind==-1) {
        cout<<"NO"<<endl;
        exit(0);
    }
    mark[eind] = 1;
    int a = edge[eind].x, b = edge[eind].y;
    if (a!=who) swap(a,b);
    int ia = i-1, ib = i-2;
    if (ind[sz[a]]!=ia) swap(ia, ib);
    solve(a, ia);
    solve(b, ib);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    fib = {1,1};
    while(fib.back()<n) fib.pb(fib.back()+fib[fib.size()-2]);
    ind.resize(2*(n+1), -1);
    loop(i,0,fib.size()) ind[fib[i]] = i;
    if (ind[n]==-1) return cout<<"NO"<<endl,0;
    g.resize(n);
    mark.resize(n-1, 0);
    edge.resize(n-1);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb({b, i});
        g[b].pb({a, i});
        edge[i] = {a,b};
    }
    sz.resize(n);
    solve(0, ind[n]);
    cout<<"YES"<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
8
1 5
1 2
2 3
3 4
5 6
6 7
7 8



8
1 2
2 3
3 4
1 5
1 6
1 7 
1 8



3
1 2
2 3


*/