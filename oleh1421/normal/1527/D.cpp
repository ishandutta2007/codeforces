#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=500010;
int n;
vector<int>g[N];
ll res=0ll;
int pos[N];
int tin[N],tout[N];
int timer=0;
int par[N];
int sub[N];
ll sz[N];
void dfs(int v,int pr){
    tin[v]=++timer;
    par[v]=pr;
    sz[v]=1;
    for (int to:g[v]){
        if (to==pr) continue;
        if (!pr){
            sub[to]=to;
        } else {
            sub[to]=sub[v];
        }
        dfs(to,v);
        sz[v]+=sz[to];
    }
    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}
ll ans[N];
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        x++;
        y++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer=0;
    int root=1;
    sub[root]=0;
    dfs(root,0);
    int a=root,b=root;
    for (int i=0;i<=n;i++) ans[i]=0;
    ans[0]=n*(n-1ll)/2ll;
    ans[1]=ans[0];
    for (int to:g[root]){
        ans[1]-=sz[to]*(sz[to]-1)/2ll;
    }
    for (int i=2;i<=n;i++){
        int v=i;
        if (upper(a,b)) swap(a,b);
        if (a==root){
            a=v;
        } else if (b==root){
            if (sub[a]==sub[v]){
                if (upper(a,v)) a=v;
                else if (!upper(v,a)) break;
            } else b=v;
        } else {
            if (sub[a]==sub[v]){
                if (upper(a,v)) a=v;
                else if (!upper(v,a)) break;
            } else if (sub[b]==sub[v]){
                if (upper(b,v)) b=v;
                else if (!upper(v,b)) break;
            } else break;
        }
        if (upper(a,b)) swap(a,b);
//        cout<<i<<" "<<a<<" "<<b<<endl;
        if (b==root){
            ans[i]=sz[a]*(n-sz[sub[a]]);
        }
        else {
            ans[i]=sz[a]*sz[b];
        }
    }
    for (int i=1;i<=n;i++){
        ans[i-1]-=ans[i];
    }
    for (int i=0;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4
0 1
0 2
0 3
**/