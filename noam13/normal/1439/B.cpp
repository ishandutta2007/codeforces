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

/*struct DSU{
    int n; 
    vi p,sz;
    DSU(int n): n(n), p(n,-1), sz(n,1){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    void uni(int a, int b){
        a = find(a), b =find(b);
        if (a==b) return ;
        if (sz[a]>sz[b]) swap(a,b);
        p[a] = b;
        sz[b]+=sz[a];
    }
};*/
int solve(){
    int n,m,k; cin>>n>>m>>k;
    vvi g(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b), g[b].pb(a);
        if (a>b) swap(a,b);
    }
    if (k*(k-1)/2 > m+10) return cout<<-1<<endl,0;
    vi deg(n);
    set<ii> s;
    loop(i,0,n) deg[i] = g[i].size(), s.insert({deg[i], i}), sort(all(g[i]));
    vi a;
    while(s.size()){
        int cur = s.begin()->y; 
        if (deg[cur]>=k) break;
        s.erase({deg[cur], cur});
        //in[cur] = 0;
        if (a.size()==0 && deg[cur]==k-1){
            vi vec;
            for(auto nei:g[cur]) {
                if (s.find({deg[nei], nei})==s.end()) continue;
                vec.pb(nei);
            }
            bool boo = 1;
            int sz = vec.size();
            loop(i,0,sz) loop(j,i+1,sz){
                if (!binary_search(all(g[vec[i]]), vec[j])) boo = 0;
            }
            if (boo){
                cout<<2<<endl<<cur+1<<" ";
                for(int x:vec) cout<<x+1<<" ";
                cout<<endl;
                return 0;
            }
        }
        for(int nei:g[cur]){
            if (s.find({deg[nei], nei})==s.end()) continue;
            s.erase({deg[nei], nei});
            deg[nei]--;
            s.insert({deg[nei], nei});
        }
    }
    if (s.size() && s.begin()->x>=k){
        cout<<1<<" "<<s.size()<<endl;
        for(auto x:s) cout<<x.y+1<<" ";
        cout<<endl;
        return 0;
    }
    /*vb in(n);
    for(int i:a) in[i] = 1;
    DSU d(n);
    for(auto e:edge){
        if (in[e.x] && in[e.y]){
            d.uni(e.x, e.y);
        }
    }
    int who = -1;
    loop(i,0,n){
        if (d.sz[i]==k)
    }*/
    cout<<-1<<endl;
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
g++ b.cpp -o a & a
3
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
10 15 3
1 2
2 3
3 4
4 5
5 1
1 7
2 8
3 9
4 10
5 6
7 10
10 8
8 6
6 9
9 7
4 5 4
1 2
2 3
3 4
4 1
1 3

*/