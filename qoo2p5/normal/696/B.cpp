#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 123;

int n;
vector<int> g[N];
int cnt[N];
double ans[N];

void dfs(int v) {
    cnt[v] = 1;
    for (int u : g[v]) {
        dfs(u);
        cnt[v] += cnt[u];
    }
}

void calc(int v) {
    for (int u : g[v]) {
        ans[u] = ans[v] + (cnt[v] - 1 - cnt[u]) / 2.0D + 1;
        calc(u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    
    dfs(1);
    ans[1] = 1;
    calc(1);
    
    for (int i = 1; i <= n; i++) {
        printf("%.10f ", ans[i]);
    }
    printf("\n");
    
    return 0;
}