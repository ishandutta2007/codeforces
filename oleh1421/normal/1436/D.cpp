#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
ll cnt[N];
int sz[N];
vector<int>g[N];
ll res=0ll;
void dfs(int v,int pr){
    cnt[v]=a[v];
    sz[v]=0;
    bool leaf=true;
    for (int to:g[v]){
        leaf=false;
        dfs(to,v);
        cnt[v]+=cnt[to];
        sz[v]+=sz[to];
    }
    sz[v]+=leaf;
    res=max(res,(sz[v]+cnt[v]-1)/sz[v]);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int p;cin>>p;
        g[p].push_back(i+1);
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    res=0;
    dfs(1,0);
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}