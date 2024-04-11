#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int a[N];
int b[N];
vector<int>g[N];
vector<int>r[N];
int used[N];
void dfs(int v){
    used[v]=1;
    for (auto to:g[v]){
        if (used[to]==2) continue;
        if (used[to]==1){
            cout<<-1<<endl;
            exit(0);
        } else {
            dfs(to);
        }
    }
    used[v]=2;
}
int dp1[N];
bool used1[N];
void dfs1(int v){
    dp1[v]=v;
    used1[v]=true;
    for (auto to:g[v]){
        if (!used1[to]) dfs1(to);
        dp1[v]=min(dp1[v],dp1[to]);
    }
}

int dp2[N];
bool used2[N];
void dfs2(int v){
    dp2[v]=v;
    used2[v]=true;
    for (auto to:r[v]){
        if (!used2[to]) dfs2(to);
        dp2[v]=min(dp2[v],dp2[to]);
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=n;i++){
        g[i].clear();
        r[i].clear();
        used[i]=used1[i]=used2[i]=false;
        dp1[i]=dp2[i]=0;
    }
    for (int i=1;i<=m;i++) {
        cin>>a[i]>>b[i];
        g[a[i]].push_back(b[i]);
        r[b[i]].push_back(a[i]);
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (r[i].empty()){
            dfs1(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (g[i].empty()){
            dfs2(i);
        }
    }
    string ans="";
    int res=0;
    for (int i=1;i<=n;i++){
        if (dp1[i]==i && dp2[i]==i) ans+='A',res++;
        else ans+='E';
    }
    cout<<res<<endl;
    cout<<ans;
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}