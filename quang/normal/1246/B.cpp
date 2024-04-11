#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
int p[N];
map<vector<pair<int, int>>, int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i; j < N; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        vector<pair<int, int>> vals;
        while (u > 1) {
            int v = p[u];
            int now = 0;
            while (u % v == 0) {
                now++;
                u /= v;
            }
            now %= k;
            if (now) vals.push_back({v, now});
        }
        cnt[vals]++;
    }
    long long res = 0;
    for (auto u : cnt) {
        vector<pair<int, int>> now = u.first;
        for (auto &v : now) {
            v.second = k - v.second;
        }
        if (now == u.first) {
            res += 1ll * u.second * (u.second - 1) / 2;
        } else if (now > u.first) {
            res += 1ll * u.second * cnt[now];
        }
    }
    cout << res << endl;
    return 0;
}