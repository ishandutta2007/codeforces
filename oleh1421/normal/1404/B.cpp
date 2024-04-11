#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int n,a,b,da,db;
vector<int>g[N];
int h[N];
void dfs(int v,int pr,int cur){
    h[v]=cur;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v,cur+1);
        }
    }
}
void solve(){
    cin>>n>>a>>b>>da>>db;
    for (int i=0;i<=n+1;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (db<=da*2) {
        cout<<"Alice\n";
        return;
    }
    dfs(a,0,0);
    if (h[b]<=da){
        cout<<"Alice\n";
        return;
    }
    int mx=1;
    for (int i=2;i<=n;i++){
        if (h[mx]<h[i]) mx=i;
    }
    dfs(mx,0,0);
    int len=0;
    for (int i=1;i<=n;i++){
        len=max(len,h[i]);
    }
    if (len<=da*2){
        cout<<"Alice\n";
        return;
    }
    cout<<"Bob\n";
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

/*
7
10 10 8 5 3
*/