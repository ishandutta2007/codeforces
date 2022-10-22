#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[200002];
int dp[200002];
bool visited[200002];
int M = -1;

void dfs(int x){
    visited[x] = true;
    int cnt = 0, m = 300000;
    for(auto u : adj[x]){
        if(!visited[u]){
            cnt++;
            dfs(u);
            m = min(m, dp[u]);
        }
    }
    if(cnt == 0) dp[x] = 1;
    else dp[x] = m+1;
    M = max(M, dp[x]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            adj[i].clear();
            visited[i] = false;
            dp[i] = 1;
            M = -1;
        }
        for(int i=1;i<n;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        visited[1] = true;

        for(auto u : adj[1]){
            visited[u] = true;
            int cnt = 0, m = 300000;
            for(auto v :adj[u]){
                if(!visited[v]){
                    cnt++;
                    dfs(v);
                    m = min(m, dp[v]);
                }
            }
            if(cnt == 0) dp[u] = 1;
            else dp[u] = m+1;
        }
        /*
        for(int i=2;i<=n;i++){
            printf("%d ", dp[i]);
        }
        printf("\n");
        */
        int temp = 0;
        int b = 0;
        for(auto u : adj[1]){
            if(temp == dp[u]){
                b = 1;
            }
            else if(temp < dp[u]){
                b = 0;
                temp = dp[u];
            }
        }
        temp += b;
        printf("%d\n", max(temp, M+1));
    }
}