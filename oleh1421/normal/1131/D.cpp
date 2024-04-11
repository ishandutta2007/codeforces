//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
char c[1010][1010];
vector<int>g[200001];
vector<int>larger[200001];
int component[200001];
int timer=0;
void dfsinit(int v){
     component[v]=timer;
     for (auto to:g[v]){
         if (!component[to]) dfsinit(to);
     }
}
int used[200001];
int dp[200001];
int timer1=0;
void dfs(int v){
    used[v]=1;
    int maxx=0;
    for (auto to:larger[v]){
        if (used[to]==1){
            cout<<"No";
            exit(0);
        }
        if (used[to]==0) dfs(to);
        maxx=max(maxx,dp[to]);
    }
    dp[v]=maxx+1;
    used[v]=2;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>c[i][j];
            if (c[i][j]=='='){
                g[i].push_back(j+n);
                g[j+n].push_back(i);
            }
        }
    }
    for (int i=1;i<=n+m;i++){
        if (!component[i]){
            timer++;
            dfsinit(i);
        }
    }


    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (c[i][j]=='<'){
                larger[component[j+n]].push_back(component[i]);
            }
            if (c[i][j]=='>'){
                larger[component[i]].push_back(component[j+n]);
            }
        }
    }
    for (int i=1;i<=timer;i++){
        if (!used[i]) dfs(i);
    }

    cout<<"Yes\n";
    for (int i=1;i<=n;i++) cout<<dp[component[i]]<<" ";
    cout<<endl;
    for (int i=n+1;i<=n+m;i++) cout<<dp[component[i]]<<" ";
    cout<<endl;
    return 0;
}