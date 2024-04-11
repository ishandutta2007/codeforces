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
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

struct DSU{
    int n;
    vi p;
    vvi g;
    DSU(int n): n(n), p(n,-1), g(n){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    void uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return ;
        p.pb(-1);
        g.pb(vi({a,b}));
        p[a] = p[b] = n;
        n++;
    }
};
struct SEG{
    int sz;
    vii a;
    SEG(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int x){
        a[i+sz] = {x,i};
        i+=sz;
        for(i/=2; i; i/=2) a[i] = max(a[2*i],a[2*i+1]);
    }
    ii query(int l, int r){
        ii res = {0,l};
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res,a[l++]);
            if (r%2==0) chkmax(res,a[r--]);
        }
        return res;
    }
};
int n,m,q; 
int sz;
vi order; 
vi in, out; int t=0;
void dfs(int cur, vvi& g){
    in[cur] = t;
    if (cur<n){
        out[cur] = ++t;
        order.pb(cur);
        return ;
    }
    for(auto nei:g[cur]) dfs(nei, g);
    out[cur] = t;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    vi arr(n); loop(i,0,n) cin>>arr[i];
    vii edge(m);
    vb del(m);
    loop(i,0,m) cin>>edge[i].x>>edge[i].y, edge[i].x--, edge[i].y--;
    vi op(q), val(q);
    loop(i,0,q) {
        cin>>op[i]>>val[i]; val[i]--;
        if (op[i]==2) del[val[i]] = 1;
    }
    DSU dsu(n);
    loop(i,0,m) if (!del[i]) dsu.uni(edge[i].x, edge[i].y);
    vi qs;
    loopr(i,0,q){
        if (op[i]==1) qs.pb(dsu.find(val[i]));
        else dsu.uni(edge[val[i]].x, edge[val[i]].y);
    }
    reverse(all(qs));
    sz = dsu.n;
    in.resize(sz); out.resize(sz);
    loop(i,0,sz){
        if (dsu.p[i]==-1){
            dfs(i, dsu.g);
        }
    }
    for(auto &x:order) x = arr[x];
    SEG seg(n);
    loop(i,0,n) seg.update(i, order[i]);
    for(auto v:qs){
        int l = in[v], r = out[v] - 1;
        ii res = seg.query(l,r);
        cout<<res.x<<endl;
        if (res.x) seg.update(res.y, 0);
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
5 4 6
1 2 5 4 3
1 2
2 3
1 3
4 5
1 1
2 1
2 3
1 1
1 2
1 2

*/