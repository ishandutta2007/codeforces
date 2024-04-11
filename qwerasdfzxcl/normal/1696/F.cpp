#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n;
bool A[101][101][101]; ///1-2 == 1-3
char buf[1111];

vector<vector<int>> construct_tree(int s){
    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> used(n+1, 0);
    adj[1].push_back(s);
    used[1] = 1, used[s] = 1;

    queue<pair<int, int>> q;
    q.emplace(s, 1);

    for (int i=1;i<=n;i++) if (!used[i]){
        if (A[1][i][s]){
            adj[1].push_back(i);
            used[i] = 1;

            q.emplace(i, 1);
        }
    }

    while(!q.empty()){
        auto [v, pa] = q.front(); q.pop();
        for (int i=1;i<=n;i++) if (!used[i]){
            if (A[v][pa][i]){
                adj[v].push_back(i);
                used[i] = 1;

                q.emplace(i, v);
            }
        }
    }

    for (int i=1;i<=n;i++) if (!used[i]){
        adj.clear();
    }
    return adj;
}

void dfs(int s, int pa, int dist, const vector<vector<int>> &adj, vector<int> &D){
    D[s] = dist;
    for (auto &v:adj[s]) if (v!=pa) dfs(v, s, dist+1, adj, D);
}

bool valid(const vector<vector<int>> &adj){
    vector<vector<int>> G = adj;
    for (int i=1;i<=n;i++){
        for (auto &v:adj[i]) G[v].push_back(i);
    }

    vector<vector<int>> D(n+1, vector<int>(n+1, 0));
    for (int i=1;i<=n;i++) dfs(i, -1, 0, G, D[i]);

    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d ", D[i][j]);
        printf("\n");
    }*/

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                bool tmp = (D[i][j]==D[i][k]);
                if (A[i][j][k]!=tmp) return 0;
            }
        }
    }

    return 1;
}

void solve(){
    ///init here
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) A[i][j][j] = 1;
    }

    ///input here

    for (int i=1;i<=n-1;i++){
        for (int j=1;j<=n-i;j++){
            scanf("%s", buf);
            for (int k=1;k<=n;k++){
                if (buf[k-1]=='0') A[k][i][i+j] = 0, A[k][i+j][i] = 0;
                else A[k][i][i+j] = 1, A[k][i+j][i] = 1;
            }
        }
    }

    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                if (A[i][j][k]) printf("1");
                else printf("0");
            }
            printf(" ");
        }
        printf("\n");
    }
*/
    ///solve here

    for (int i=2;i<=n;i++){
        auto adj = construct_tree(i);
        if (adj.empty()) continue;
        //printf("ok %d\n", i);
        if (valid(adj)){
            printf("Yes\n");
            for (int i=1;i<=n;i++){
                for (auto &v:adj[i]) printf("%d %d\n", i, v);
            }
            return;
        }
    }

    printf("No\n");

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}