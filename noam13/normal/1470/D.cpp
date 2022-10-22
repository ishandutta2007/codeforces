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
const int INF = 4e18, MOD = 1e9+7;

vvi g;
int solve(){
    int n,m; cin>>n>>m;
    g.clear(); g.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi check(n, -1);
    queue<int> q; q.push(0);
    while(q.size()){
        int cur = q.front(); q.pop();
        int pos = 1;
        for(int nei:g[cur]) {
            if(check[nei]==1) pos = 0;
            else if (check[nei]==-1) q.push(nei), check[nei] = -2;
        }
        check[cur] = pos;
    }
    vi ans;
    loop(i,0,n) {
        if(check[i]==1) ans.pb(i);
        else if (check[i]==-1) return cout<<"NO"<<endl,0;
    }
    cout<<"YES"<<endl<<ans.size()<<endl;
    for(int x:ans) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
2
3 2
3 2
2 1
4 2
1 4
2 3

*/