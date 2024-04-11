#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int adj[300300], a[300300], b[300300], cnt[300300];
bool visited[300300];

void dfs(int s){
    visited[s] = 1;
    if (!visited[adj[s]]) dfs(adj[s]);
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    fill(cnt, cnt+n+1, 0);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    for (int i=1;i<=n;i++){
        b[i] = i-a[i];
        if (b[i]<0) b[i] += n;
        cnt[b[i]]++;
    }
    vector<int> ans;
    for (int z=0;z<n;z++){
        if (cnt[z]<n/3-1) continue;
        for (int i=1;i<=n;i++) adj[a[i]] = (i-z+n-1)%n+1;
        fill(visited+1, visited+n+1, 0);
        int val = 0;
        for (int i=1;i<=n;i++) if (!visited[i]){
            val++;
            dfs(i);
        }
        if (val>=n-m) ans.push_back(z);
    }
    printf("%d ", (int)ans.size());
    sort(ans.begin(), ans.end());
    for (auto &x:ans) printf("%d ", x);
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