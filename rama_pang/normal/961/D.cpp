#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> P[100005];
int can[100005];

bool solve(int p1, int p2) {
    memset(can, 0, sizeof(can));
    can[p1] = 1;
    can[p2] = 1;
    for (int i = 0; i < N; i++) {
        if (i == p1 || i == p2) {
            continue;
        }
        if (1ll * (P[p2].second - P[p1].second) * (P[i].first - P[p1].first) == 1ll * (P[p2].first - P[p1].first) * (P[i].second - P[p1].second)) {
            can[i] = 1;
        }
    }
    int j1 = -1, j2 = -1;
    for (int i = 0; i < N; i++) {
        if (can[i]) {
            continue;
        }
        if (j1 == -1) {
            j1 = i;
        } else {
            j2 = i;
        }
    }
    if (j1 == -1 || j2 == -1) {
        return true;
    }
    can[j1] = 1;
    can[j2] = 1;

    for (int i = 0; i < N; i++) {
        if (can[i]) {
            continue;
        }
        if (1ll * (P[j2].second - P[j1].second) * (P[i].first - P[j1].first) == 1ll * (P[j2].first - P[j1].first) * (P[i].second - P[j1].second)) {
            can[i] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (can[i]) {
            continue;
        }
        return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    if (N <= 4 || solve(0, 1) || solve(0, 2) || solve(1, 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}