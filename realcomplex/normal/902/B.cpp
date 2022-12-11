#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 9;
vector<int>G[N];
int col[N];
bool vis[N];
int ans;

void dfs(int u,int c){
    vis[u]=true;
    if(c!=col[u])ans+=1,c=col[u];
    for(auto x : G[u]){
        if(vis[x])continue;
        dfs(x,c);
    }
}

int main(){
    int n;
    cin >> n;
    int a;
    for(int i = 2;i<=n;i++){
        cin >> a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    for(int i = 1;i<=n;i++)
        cin >> col[i];
    dfs(1,0);
    cout << ans << "\n";
    return 0;
}