#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[100100];
int deg[100100], b[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<=n;i++){
        adj[i].clear();
        deg[i] = 0;
    }
    bool flag = 0;
    for (int i=1;i<=n;i++){
        scanf("%d", b+i);
        if (b[i]==n+1 || b[i]==0){
            adj[0].push_back(i);
            deg[i]++;
            if (b[i]==n+1) flag = 1;
        }
        if (b[i]!=0 && b[i]!=n+1){
            adj[b[i]].push_back(i);
            deg[i]++;
        }
    }

    vector<pair<int, int>> E;
    int k = 0;
    for (int i=0;i<=n;i++) if (!adj[i].empty()){
        int idx = -1;

        int val = i;
        if (flag && val==0) val = n+1;
        if (val > adj[i].back()){
            for (auto &x:adj[i]) k = max(k, x);
        }

        for (auto &x:adj[i]) if (!adj[x].empty()){
            assert(idx==-1);
            idx = x;
        }

        if (idx==-1) continue;
        for (auto &x:adj[i]) if (x!=idx) E.emplace_back(x, idx);
    }

    for (auto &[x, y]:E){
        adj[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i=0;i<=n;i++) if (!deg[i]) q.push(i);

    while(!q.empty()){
        auto s = q.front(); q.pop();
        ans.push_back(s);
        for (auto &v:adj[s]){
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }

    assert((int)ans.size()==n+1);
    printf("%d\n", k);
    for (auto &x:ans) if (x) printf("%d ", x);
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