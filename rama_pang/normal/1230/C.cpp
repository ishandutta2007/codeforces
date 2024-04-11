#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;

int N, M, ans = 0;

int u[100], v[100];
int color[10];
void bf(int n) {
    if (n > N) {
        int res = 0;
        int dom[7][7]; memset(dom, 0, sizeof(dom));
        for (int i = 0; i < M; i++) {
            int a = color[u[i]], b = color[v[i]];
            if (dom[min(a, b)][max(a, b)] == 0) {
                res++;
            }
            dom[min(a, b)][max(a, b)] = 1;
        }
        // for (int i = 1; i <= N; i++) {
        //     cout << color[i];
        // }
        // cout << " " << res << "\n";
        ans = max(ans, res);
    } else {
        for (int i = 1; i <= 6; i++) {
            color[n] = i;
            bf(n + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
    }
    bf(1);
    cout << ans << "\n";
}