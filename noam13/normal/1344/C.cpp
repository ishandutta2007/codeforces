#include <bits/stdc++.h>
#define int int64_t
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
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vvi ag(n), g(n);
    vi deg(n,0);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b);
        ag[b].pb(a);
        deg[a]++;
    }
    vi tmp = deg;
    queue<int> q;
    vi ans(n,0);
    loop(i,0,n) if (deg[i]==0) q.push(i);
    vb visit(n,0);
    vi order;
    while(q.size()){
        int cur = q.front(); q.pop();
        visit[cur] = 1;
        order.pb(cur);
        for(auto nei:ag[cur]){
            if (visit[nei]) return cout<<-1<<endl,0;
            if (--deg[nei]==0) q.push(nei);
        }
    }
    loop(i,0,n) if (!visit[i]) return cout<<-1<<endl,0;
    if (order.size()!=n) return cout<<-1<<endl,0;
    vi down(n), up(n);
    loop(i,0,n) down[i] = up[i] = i;
    for(auto cur:order){    
        for(auto nei:g[cur]) chkmin(down[cur], down[nei]);
    }
    reverse(all(order));
    for(auto cur:order){
        for(auto nei:ag[cur]) chkmin(up[cur], up[nei]);
    }
    loop(i,0,n) ans[i] = (min(up[i], down[i])==i);
    int cnt = 0; loop(i,0,n) cnt+=(ans[i]==1);
    cout<<cnt<<endl;
    loop(i,0,n) cout<<(ans[i]==1?'A':'E');
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
2 1
1 2

*/