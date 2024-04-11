#include <bits/stdc++.h>
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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int MOD = 998244353;

vvi g;
vvi d;
void dfs(int cur, int p=-1, int dp=0){
    if (dp==d.size()) d.pb(vi(0));
    d[dp].pb(cur);
    for(auto nei:g[cur]) if (nei!=p) {
        dfs(nei, cur, dp+1);
    }
}
ii ask(int dp){
    //cout<<"DEPTH: "<<dp<<endl;
    vi a;
    loop(i,dp,d.size()) for(auto x:d[i]) a.pb(x);
    cout<<"? "<<a.size(); for(auto i:a) cout<<" "<<i+1; cout<<endl;
    ii res; cin>>res.x>>res.y; res.x--;
    return res;
}
vi cand;
int v;
void dfs2(int cur, int p=-1, int dp=0){
    //cout<<"VISIT: "<<cur<<endl;
    if (dp==v){
        cand.pb(cur);
        return ;
    }
    for(auto nei:g[cur]) if (nei!=p) dfs2(nei, cur, dp+1);
}
void solve(){
    int n; cin>>n;
    g.clear(); g.resize(n);
    d.clear();
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    cout<<"? "<<n; loop(i,0,n) cout<<" "<<i+1; cout<<endl;
    int root; cin>>root>>v; root--;
    dfs(root);
    int l = max(1,(v+1)/2), r = min((int)d.size(),v+1);
    int mid, ans=-1;
    while(l<r){
        mid = (l+r) / 2;
        ii p = ask(mid);
        if (p.y==v) l = mid+1, ans = p.x;
        else r = mid;
    }
    cand.clear();
    dfs2(ans);
    int b=cand[0];
    if (cand.size()>1){
        cout<<"? "<<cand.size(); for(auto i:cand) cout<<" "<<i+1; cout<<endl;
        cin>>b>>v; b--;
    }
    cout<<"! "<<ans+1<<" "<<b+1<<endl;
    string verd; cin>>verd;
}

int32_t main(){
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a

*/