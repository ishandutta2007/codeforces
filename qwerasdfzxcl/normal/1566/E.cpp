#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[200200];
bool bud[200200], leaf[200200];
int ans1 = 0, ans2 = 0;

void dfs1(int s, int rt, int pa = -1){
    bool flag1 = 1, flag2 = 1;
    int cnt = 0;
    for (auto &v:adj[s]) if (v!=pa){
        dfs1(v, rt, s);
        if (!leaf[v] && !bud[v]) flag1 = 0;
        else if (leaf[v]) cnt++;
        if (!bud[v]) flag2 = 0;
    }
    if (flag2) {leaf[s] = 1; return;}
    if (flag1 && s!=rt){
        bud[s] = 1;
        ans1 += cnt-1;
    }
}

void dfs2(int s, int pa = -1){
    bool flag = 1;
    for (auto &v:adj[s]) if (v!=pa && !bud[v]){
        flag = 0;
        dfs2(v, s);
    }
    if (flag) ans2++;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, 1);
    dfs2(1);
    printf("%d\n", ans1+ans2);
    ///init
    for (int i=1;i<=n;i++){
        adj[i].clear();
        bud[i] = leaf[i] = 0;
        ans1 = ans2 = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}