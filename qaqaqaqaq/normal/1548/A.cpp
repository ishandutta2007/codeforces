#include<bits/stdc++.h>
#define int long long

using namespace std;

#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=200007;
int n,m,q;
set<int> g[maxn];
bool vis[maxn];
int ans=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rep1(i,n) g[i].insert(0);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        g[u].insert(v), g[v].insert(u);
    }
    rep1(i,n){
        auto ret=prev(g[i].end());
        if (*ret<i) ans++, vis[i]=1;
    }
    cin>>q;
    while (q--){
        int t;
        cin>>t;
        if (t==1){
            int u,v;
            cin>>u>>v;
            g[u].insert(v), g[v].insert(u);
            if (vis[u]&&v>u) vis[u]=0, ans--;
            if (vis[v]&&v<u) vis[v]=0, ans--;
        }
        if (t==2){
            int u,v;
            cin>>u>>v;
            g[u].erase(v), g[v].erase(u);
            if (!vis[u]&&*prev(g[u].end())<u) vis[u]=1, ans++;
            if (!vis[v]&&*prev(g[v].end())<v) vis[v]=1, ans++;
        }
        if (t==3){
            cout<<ans<<"\n";
        }
    }
}