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

void dfs(int cur, vvi& g, vb& check, vi& v){
    if (check[cur]) return ;
    check[cur] = 1;
    for(auto nei:g[cur]) dfs(nei, g, check, v);
    v.pb(cur);
}
int solve(){
    int n; cin>>n;
    string s; cin>>s;
    vvi g(n), ag(n);
    loop(i,0,n){
        int j = (i+1)%n;
        if (s[i]!='>') g[j].pb(i), ag[i].pb(j);
        if (s[i]!='<') g[i].pb(j), ag[j].pb(i);
    }
    vi order;
    vb check(n);
    loop(i,0,n) dfs(i, g, check, order);
    reverse(all(order));
    fill(all(check),0);
    int ans = 0;
    for(int i:order){
        if (check[i]) continue;
        vi v;
        dfs(i, ag, check, v);
        if (v.size()>1) ans+=v.size();
    }
    cout<<ans<<endl;
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
g++ a.cpp -o a & a
4
4
-><-
5
>>>>>
3
<--
2
<>


*/