#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

vi c;
vvi g;
vi sz, big;
vi st,et, ver;
int t=0;
int predfs(int cur, int p=-1){  
    ver[t] = c[cur];
    st[cur] = t++;
    sz[cur] = 1;
    int maxsz = -1;
    for(auto nei:g[cur]) if (nei!=p) {
        sz[cur]+=predfs(nei, cur);
        if (sz[nei]>maxsz) big[cur] = nei;
    }
    et[cur] = t;
    return sz[cur];
}
vector<int64_t> ans;
vi counter;
int64_t dominate=0, num=0;
inline void add(int col){
    counter[col]++;
    int cntcol = counter[col];
    if (cntcol>num){
        num++;
        dominate = col;
    }
    else if (cntcol==num){
        dominate +=col;
    }
}
void dfs(int cur, int p=-1, bool keep=0){
    if (big[cur]==-1){
        ans[cur] = c[cur];
        if (keep){
            dominate = c[cur];
            counter[c[cur]] = 1;
            num = 1;
        }
        return ;
    }

    for(auto nei:g[cur]) if (nei!=p && nei!=big[cur]) dfs(nei, cur,0);
    dfs(big[cur], cur,1);
    for(auto nei:g[cur]) if (nei!=p && nei!=big[cur]) {
        loop(i,st[nei], et[nei]) {
            add(ver[i]);
        }
    }
    add(c[cur]);
    ans[cur] = dominate;
    if (!keep){
        loop(i,st[cur],et[cur]) counter[ver[i]]--;
        dominate  = num = 0;
    }
}  
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    c = vi(n); g = vvi(n);
    loop(i,0,n) cin>>c[i];
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    sz = big = ver = st = et = vi(n,-1);
    counter = vi(n+1,0);
    ans.resize(n);
    predfs(0);
    //loop(i,0,n) cout<<sz[i]<<" "; cout<<endl;
    dfs(0);
    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ sack.cpp -o b & b
8
4 1 5 3 3 2 4 1
*/