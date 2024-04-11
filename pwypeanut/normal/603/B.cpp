#include <bits/stdc++.h>
using namespace std;

int P, K, to[1000005];
bool vis[1000005];

int inverse(int x) {
    return ((long long)x * K) % P;
}

void dfs(int x) {
    if (vis[x]) return;
    else vis[x] = 1;
    dfs(to[x]);
}

int main() {
    scanf("%d%d", &P, &K);
    for (int i = 0; i < P; i++) {
        to[i] = inverse(i);
    }
    int cnt = 0;
    for (int i = 1; i < P; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (K == 1) cnt++;
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= P;
        ans %= 1000000007;
    }
    cout << ans << endl;
}