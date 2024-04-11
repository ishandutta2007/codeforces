#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 1e18;
const int MAXD = 1e6+5, SQRT=1e3+2;
vvi g(MAXD);
vi dist(MAXD), pre(MAXD,-1);
int sub(int x, int d){
    int cnt=0;
    while(x%d==0) x/=d,cnt++;
    if (cnt%2) return x*d;
    return x;
}
int bfs(int st){
    loop(i,0,MAXD) dist[i]=-1; dist[st]=0;
    queue<int> q; q.push(st);
    int ans=INF, maxd=MAXD;
    while(q.size()){
        int cur = q.front(); q.pop();
        if (dist[cur]>maxd) break;
        for(auto nei:g[cur]){
            if (nei==pre[cur]) continue;
            if (dist[nei]==-1){
                dist[nei] = dist[cur]+1; pre[nei]=cur;
                q.push(nei);
            }
            else{
                maxd = dist[cur];
                chkmin(ans, dist[nei]+dist[cur]+1);
            }
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    vvi fact(MAXD);
    loop(f,2,MAXD){
        if (fact[f].size()==0){
            for(int j=f;j<MAXD;j+=f) fact[j].pb(f);
        }
    }
    loop(i,0,n){
        int x = a[i];
        vi div = fact[x];
        for(auto d:div) x = sub(x,d);
        if (x==1) return cout<<1<<endl,0;
        div = fact[x];
        if (div.size()==1) div.pb(1);
        g[div[0]].pb(div[1]); g[div[1]].pb(div[0]);
    }
    int ans=INF;
    loop(i,1,SQRT) if (g[i].size()) chkmin(ans, bfs(i));
    if (ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
3
1 4 6


*/