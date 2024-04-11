#include <bits/stdc++.h>

using namespace std;

const int SZ = 531441;
const int W = 12;

int n, m, w;
int cnt[1 << W];
int p3[W + 1];
int a[SZ + 10];

void go(int u, int id, int mask) {
    if (id >= w) {
        a[mask] += cnt[u];
        return;
    }
    go(u, id + 1, mask + 2 * p3[id]);
    go(u, id + 1, mask + ((u >> id) & 1) * p3[id]); 
}

int getAns(const string &u, int id, int mask2, int mask3) {
    if (id == w) {
        return cnt[mask2] * a[mask3];
    }
    int p1, p2;
    if (u[id] == 'A') {
        p1 = getAns(u, id + 1, mask2 | (1 << id), mask3);
        p2 = getAns(u, id + 1, mask2, mask3 + 2 * p3[id]);
    } else if (u[id] == 'O') {
        p1 = getAns(u, id + 1, mask2, mask3);
        p2 = 0;
    } else if (u[id] == 'X') {
        p1 = getAns(u, id + 1, mask2, mask3);
        p2 = getAns(u, id + 1, mask2 | (1 << id), mask3 + p3[id]);
    } else if (u[id] == 'a') {
        p1 = getAns(u, id + 1, mask2 | (1 << id), mask3 + p3[id]);
        p2 = 0;
    } else if (u[id] == 'o') {
        p1 = getAns(u, id + 1, mask2, mask3 + p3[id]);
        p2 = getAns(u, id + 1, mask2 | (1 << id), mask3 + 2 * p3[id]);
    } else {
        p1 = getAns(u, id + 1, mask2, mask3 + p3[id]);
        p2 = getAns(u, id + 1, mask2 | (1 << id), mask3);
    }
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> n >> m;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        cnt[u]++;
    }
    p3[0] = 1;
    for (int i = 1; i <= w; i++) {
        p3[i] = p3[i - 1] * 3;
    }
    for (int i = 0; i < (1 << w); i++) {
        go(i, 0, 0);
    }
    while (m--) {
        string u;
        cin >> u;
        reverse(u.begin(), u.end());
        int res = getAns(u, 0, 0, 0);
        cout << res << '\n';
    }
    return 0;
}