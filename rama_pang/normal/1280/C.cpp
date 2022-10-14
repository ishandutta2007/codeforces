#include <bits/stdc++.h>
#define int long long
using namespace std;
using lint = long long;
vector<pair<int, int>> G[200005];
int ansG, ansB;
int sz[200005];
int N;

void dfsG(int n, int p, bool end) {
    sz[n] = 1;
    for (auto i : G[n]) {
        if (i.first == p) {
            if (end) {
                ansG += i.second;
            }
            continue;
        }
        dfsG(i.first, n, end);
        sz[n] += sz[i.first];
        if (sz[i.first] % 2 == 1) {
            ansG += i.second;
        }
    }
}

void dfsB(int n, int p, bool end) {
    for (auto i : G[n]) {
        if (i.first == p) {
            if (end) {
                ansG += i.second;
            }
            continue;
        }
        dfsB(i.first, n, end);
        ansB += i.second * min(N + N - sz[i.first], sz[i.first]);
    }
}

int solve() {
    ansG = ansB = 0;
    cin >> N;

    for (int i = 0; i <= 2 * N; i++) {
        G[i].clear();
        sz[i] = 0;
    }
    for (int i = 1; i < 2 * N; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        G[a].emplace_back(b, t);
        G[b].emplace_back(a, t);
    }
    int rootG = 0;
    for (int i = 1; i <= 2 * N; i++) {
        if (G[i].size() == 1) {
            rootG = i;
            break;
        }
    }
    dfsG(rootG, -1, false);
    dfsB(rootG, -1, false);
    cout << ansG << " " << ansB << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int T;
    cin >> T;
    while (T--) {
        solve();
    }    




    return 0;
}