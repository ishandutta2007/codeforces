#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int w[N];
int deg[N];
int order[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            sum += w[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }   
        iota(order + 1, order + n + 1, 1);
        sort(order + 1, order + n + 1, [&](int u, int v) {
            return w[u] > w[v];
        });

        int curId = 1;
        for (int i = 1; i < n; i++) {
            cout << sum << ' ';
            if (i + 1 < n) {
                while (deg[order[curId]] == 1) {
                    curId++;
                }
                deg[order[curId]]--;
                sum += w[order[curId]];
            }
            // cout << i << ' ' << curId << ' ' << order[curId] << w[order[curId]] << endl;
        }
        cout << '\n';

        // reset
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
        }
    }
    return 0;
}