#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char tmp[300300];
vector<pair<int, int>> adj[300300][2];
int v[300300][2], cur=1, ans[300300];
vector<int> c;

void dfs(int s1, int s2){
    if (v[s1][s2]) return;
    v[s1][s2]=cur;
    c.back()++;
    for (auto p:adj[s1][s2]) dfs(p.first, p.second);
}

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", tmp);
    for (int i=0;i<=n;i++){
        adj[i][0].clear();
        adj[i][1].clear();
        v[i][0]=0, v[i][1]=0;
        ans[i]=0;
    }
    cur=1;
    c.clear();
    for (int i=0;i<n;i++){
        if (tmp[i]=='L'){
            adj[i+1][0].push_back(make_pair(i, 1));
            adj[i][1].push_back(make_pair(i+1, 0));
        }
        else{
            adj[i][0].push_back(make_pair(i+1, 1));
            adj[i+1][1].push_back(make_pair(i, 0));
        }
    }
    c.push_back(-1);
    for (int i=0;i<=n;i++, cur++){
        c.push_back(0);
        dfs(i, 0);
        ans[i]=c[v[i][0]];
    }
    for (int i=0;i<=n;i++) printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}