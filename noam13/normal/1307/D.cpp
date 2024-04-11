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
const int INF = 1e18, MOD=1e9+7;

int n,m;
vvi g;
vi bfs(int s){
    vi dist(n,INF);dist[s]=0;
    queue<int> q; q.push(s);
    while(q.size()){
        int cur = q.front(); q.pop();
        for(auto nei:g[cur]){
            if (dist[nei]==INF){
                dist[nei] = dist[cur] + 1;
                q.push(nei);
            }
        }
    }
    return dist;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>m>>k;
    vi spec(k); 
    loop(i,0,k) cin>>spec[i], spec[i]--;
    g.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--,b--;
        g[a].pb(b); g[b].pb(a);
    }
    vi distu = bfs(0);
    vi distv = bfs(n-1);
    vi du(k),dv(k);
    vii rel(k);
    loop(i,0,k) du[i]=distu[spec[i]],dv[i]=distv[spec[i]],rel[i]={distu[spec[i]]-distv[spec[i]],i};
    sort(all(rel));
    int maxu = -INF, ans=0;
    loop(j,0,k){
        int i = rel[j].y;
        chkmax(ans, maxu + dv[i] + 1);
        chkmax(maxu,du[i]);
    }
    chkmin(ans, distv[0]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ CowFields.cpp -o a & a
5 4 2
2 4
1 2
2 3
3 4
4 5






*/