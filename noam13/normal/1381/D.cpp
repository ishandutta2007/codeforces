#include <bits/stdc++.h>
//#define int int64_t
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
const int INF = 2e9, MAXN=1e5+123;

int n,x,y;
int sz;
vi g[MAXN];


bool col[MAXN];
ii fir[MAXN], sec[MAXN];
int notc[MAXN];
vi aa;
bool dfs(int cur, int p=-1, int d=1){
    int v = 0;
    if (cur==y) sz = d, v=1;
    fir[cur] = {0,-1};
    sec[cur] = {0,-1};
    for(auto nei:g[cur]) if(nei!=p){
        if (dfs(nei, cur, d+1)) v=1;
        int curv = fir[nei].x;
        if (curv>fir[cur].x) sec[cur] = fir[cur], fir[cur] = {curv,nei};
        else if (curv>sec[cur].x) sec[cur] = {curv, nei};
    }
    fir[cur].x++; sec[cur].x++;
    if (v) {
        aa.pb(cur);
        for(auto nei:g[cur]) if(nei!=p){
            if (!col[nei]) chkmax(notc[cur], fir[nei].x);
        }
    }
    return col[cur]=v;
}

bool ans[MAXN];
void dfs2(int cur,int p=-1, int up=0){
    for(auto nei:g[cur]) if(nei!=p){
        if (nei==fir[cur].y) dfs2(nei,cur, max(sec[cur].x, up)+1);
        else dfs2(nei, cur, max(fir[cur].x, up)+1);
    }
    int cnt = (up>=sz);
    for(auto nei:g[cur]) if(nei!=p) cnt+=(fir[nei].x+1>=sz);
    if (cnt>2) ans[cur]=1;
}
int res = 0;
void check(int cur, int p=-1){
    for(auto nei:g[cur]) if(nei!=p){
        if (!col[nei]) check(nei, cur);
    }
    if (ans[cur]) res=1;
}
bool can(){
    loop(i,0,n){
        col[i] = notc[i] = ans[i] = 0;
    }
    aa.clear();
    dfs(x);
    int frex = fir[y].x;
    dfs2(x);
    int l = 0, r = sz-1, turn = 0;
    res = 0; check(aa[l]); check(aa[r]);
    int bestl = notc[aa[r]], bestr = sz-1-notc[aa[l]];
    //cout<<aa[l]<<" "<<aa[r]<<endl;
    while(l<r){
        //cout<<"LR: "<<l<<" "<<bestl<<" "<<r<<" "<<bestr<<endl;
        if (bestl>l){
            l++;
            check(aa[l]);
            chkmin(bestr, sz -1 - notc[aa[l]] + l);
            continue;
        }
        if (bestr<r){
            r--;
            check(aa[r]);
            chkmax(bestl, notc[aa[r]]-(sz-(r+1)));
            continue;
        }
        break;
    }
    return res;
}
int solve(){
    cin>>n>>x>>y; x--; y--;
    loop(i,0,n) g[i].clear();
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    } 
    if (can()) return cout<<"YES"<<endl,0; 
    /*swap(x,y);
    if (can()) return cout<<"YES"<<endl,0; */
    cout<<"NO"<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
4
8 4 7
1 2
2 3
1 4
4 5
4 6
1 7
7 8
4 3 2
4 3
1 2
2 3
9 3 5
1 2
2 3
3 4
1 5
5 6
6 7
1 8
8 9
16 15 12
1 2
2 3
1 4
4 5
5 6
6 7
4 8
8 9
8 10
10 11
11 12
11 13
13 14
10 15
15 16

*/