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
const int INF = 4e18, MOD = 998244353;

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) % MOD;
}
void add(int &a, int b){
    a = (a+b)%MOD;
}
void sub(int &a, int b){
    a = (a-b)%MOD;
    if (a<0) a+=MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vvi ag(n), g(n);
    vi deg(n), grun(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        ag[b].pb(a);
        deg[a]++;
    }
    queue<int> q;
    loop(i,0,n) if(deg[i]==0) q.push(i);
    int k = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        vi vec;
        for(int nei:g[cur]) vec.pb(grun[nei]);
        sort(all(vec));
        grun[cur] = 0;
        loop(i,0,vec.size()) {
            if (vec[i]==grun[cur]) grun[cur]++;
        }
        chkmax(k, grun[cur]);
        for(int nei:ag[cur]) if(--deg[nei]==0) q.push(nei);
    }
    k++;
    int sz = 1; for(;sz<k;sz*=2);
    vi cnt(sz);
    loop(i,0,n) cnt[grun[i]]++;
    vvi mat(sz, vi(sz+1));
    int invnn = pp(n+1, MOD-2);
    loop(i,0,sz){
        loop(j,0,sz){
            mat[i][j] = (MOD - cnt[i^j] + (i==j?n+1:0))%MOD;
        }
        if (i) add(mat[i][sz], 1);
    }
    loop(i,0,sz){
        int f = -1;
        loop(j,i,sz){
            if (mat[j][i]) {
                f = j;
                break;
            }
        }
        assert(f != -1);
        if (f!=i) swap(mat[i], mat[f]);
        int inv = pp(mat[i][i], MOD-2);
        loop(k,i,sz+1) mat[i][k] = mat[i][k] * inv % MOD;
        loop(j,i+1,sz+(i!=0)){
            if (j==sz) j = 0;
            int mult = (MOD - mat[j][i])%MOD;
            loop(k,i,sz+1) add(mat[j][k], mult * mat[i][k] % MOD);
            if (j==0) break;
        }
    }
    cout<<mat[0][sz]<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
2 1
1 2




*/