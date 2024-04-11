#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000007
#define N 100010

using namespace std;

int n;
vector <int> a[N];
int color[N];
long long dp[N][2];
bool past[N];

void DFS(int u) {
    if(color[u]) dp[u][1] = 1;
    else dp[u][0] = 1;
    past[u] = 1;
    for(int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i];
        if(!past[v]) {
            DFS(v);
            dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][1]) % MAX;
            dp[u][1] = (dp[u][1] + dp[u][0] * dp[v][1]) % MAX;
            dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MAX;
        }
    }
}

int main() {
    //fi, fo;
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n - 1; i++) {
        scanf("%d", &x);
        a[i].push_back(x);
        a[x].push_back(i);
    }
    for(int i = 0; i <= n - 1; i++) scanf("%d", &color[i]);
    DFS(0);
    printf("%I64d", dp[0][1]);
    return 0;
}