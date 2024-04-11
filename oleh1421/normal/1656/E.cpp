#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
vector<int>g[N];
int a[N];
void dfs(int v,int pr){
    int cnt=0;
    for (int to:g[v]){
        if (to==pr) continue;
        a[to]=1-a[v];
        dfs(to,v);
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        if (g[i].size()>1){
            v.push_back({g[i].size(),i});
        }
    }
    if (v.size()==1){
        for (int i=1;i<=n;i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    sort(v.begin(),v.end());
    int root=v[0].second;
    a[root]=1;
    for (int to:g[root]){
        a[to]=2;
        dfs(to,root);
    }
    a[root]=1-(int)g[root].size()*2;
    for (int i=1;i<=n;i++){
        if (i==root) continue;
        a[i]-=((int)(g[i].size())-1)*(1-a[i]);
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

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

//2
//
//1 2

/**



**/