#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define z second.first
#define id second.second
#define fi first
#define se second
#define int long long
using namespace std;
int N;
pair<pair<int, int>, pair<int, int>> P[50005];
pair<int, pair<int, int>> dist[5000005];
bool used[2005];

void dp(int le, int ri) {
    if (le > ri) return;
    dp(le + 1, ri - 1);
    cout << P[le].id + 1 << " " << P[ri].id + 1 << "\n";
}

int32_t main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i].x >> P[i].y >> P[i].z;
        P[i].id = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                dist[i * N + j].fi = 1e18;
                continue;
            }
            dist[i * N + j].fi = (P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y) + (P[i].z - P[j].z) * (P[i].z - P[j].z);
            dist[i * N + j].se.fi = min(i, j);
            dist[i * N + j].se.se = max(i, j);
        }
    }
    sort(dist, dist + N * N);
    for (int i = 0; i < N * N; i++) {
        if (used[dist[i].se.fi] || used[dist[i].se.se]) continue;
        used[dist[i].se.fi] = 1;
        used[dist[i].se.se] = 1;
        cout << dist[i].se.fi + 1 << " " << dist[i].se.se + 1 << "\n";
    }
    // sort(P, P + N);
    // dp(0, N - 1);
    // for (int i = )
}