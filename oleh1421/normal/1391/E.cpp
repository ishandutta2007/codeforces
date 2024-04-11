//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
vector<int>g[N];
int h[N];
int p[N];
int sz[N];
void dfs(int v,int pr){
    p[v]=pr;
    h[v]=h[pr]+1;
    sz[v]=1;
    for (int to:g[v]){
        if (!h[to]){
            dfs(to,v);
            sz[v]+=sz[to];
        }
    }
}
vector<int>group[N];
bool used[N];
vector<int>order;
void dfs2(int v){
    used[v]=true;
    order.push_back(v);
    for (int to:g[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
}
void dfs1(int v){
    if (sz[v]*2<=sz[1]-h[v]+1){
        dfs2(v);
        return;
    }
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs1(to);
        }

    }

}

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) g[i].clear(),group[i].clear();
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++) h[i]=p[i]=0;
    h[0]=0;
    dfs(1,0);
    int Mx=1;
    for (int i=2;i<=n;i++){
        if (h[i]>h[Mx]) Mx=i;
    }
    if (h[Mx]*2>=n){
        cout<<"PATH\n";
        vector<int>ans;
        while (Mx){
            ans.push_back(Mx);
            Mx=p[Mx];
        }
        cout<<ans.size()<<endl;
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
        return;
    }
    order.clear();
    for (int i=1;i<=n;i++) used[i]=false;
    dfs1(1);
    int k=order.size()/2;
    cout<<"PAIRING\n"<<k<<endl;
    for (int i=0;i<k;i++){
        cout<<order[i]<<" "<<order[i+k]<<endl;
    }

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*

3 0
aa
bcd
*/