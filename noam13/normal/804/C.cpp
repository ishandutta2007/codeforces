#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;


vvi g;
vvi col;

int res = 1;
vi ans;
bool cmp(int l, int r){
    return ans[l]<ans[r];
}
void dfs(int cur, int p=-1){
    sort(all(col[cur]), cmp);
    int j = col[cur].size() - 1, cnt = res;
    for(auto x:col[cur]) {
        if (ans[x]!=0) continue;
        while(j>=0 && cnt==ans[col[cur][j]]) j--, cnt--;
        ans[x] = cnt--;
    }
    for(auto nei:g[cur]) if(nei!=p) dfs(nei, cur);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    g.resize(n); col.resize(n); ans.resize(m);
    loop(i,0,n){
        int r; cin>>r;
        chkmax(res, r);
        loop(j,0,r){
            int x; cin>>x; x--;
            col[i].pb(x);
        }
    }
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0);
    cout<<res<<endl;
    loop(i,0,m) cout<<max(ans[i],1)<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ IceCreamColoring.cpp -o a & a
3 3
1 1
2 2 3
1 2
1 2
2 3

*/