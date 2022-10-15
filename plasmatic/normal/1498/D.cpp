// ./d-bananas-in-a-microwave.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MM = 1e5 + 1;
int N, M,
    ans[MM], dis[MM];
ll cto[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    memset(ans, -1, sizeof ans);
    ans[0] = 0;
    for (auto i = 0; i < N; i++) {
        int t, y; ll x; cin >> t >> x >> y;

        memset(dis, 0x3f, sizeof dis);
        for (auto j = 0; j < M; j++) {
            if (t == 1) cto[j] = (j * 100000LL + x + 99999) / 100000;
            else cto[j] = (j * x + 99999) / 100000;

            if (ans[j] != -1) dis[j] = 0;
        }
        if (ans[M] != -1) dis[M] = 0;

        for (auto j = 0; j <= M; j++) {
            if (cto[j] <= M)
                dis[cto[j]] = min(dis[cto[j]], dis[j] + 1);
            if (ans[j] == -1 && dis[j] <= y)
                ans[j] = i+1;
        }
    }
    for (auto i = 1; i <= M; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}