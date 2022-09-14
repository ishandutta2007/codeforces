#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
int a[N];
vector<int>g[N];
bool used[N];
vector<pair<int,int> >ans;
void dfs(int v){
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            ans.push_back({v,to});
            dfs(to);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],g[i].clear(),used[i]=false;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i]!=a[j]) g[i].push_back(j);
        }
    }
    ans.clear();
    dfs(1);
    if (ans.size()<n-1) cout<<"NO\n";
    else {
        cout<<"YES\n";
        for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}