#include <bits/stdc++.h>

using namespace std;

const int N = 500;

int n;
int a[N][N];
int id[N];

int ask(int u, int v) {
    cout << "? " << u << ' ' << v << endl << flush;
    char res;
    cin >> res;
    return res == '<';
}

int fight(int u, int v) {
    if (a[u][v] != 0) return a[u][v];
    int smaller = ask(u, v);
    if (smaller) {
        a[u][v] = -1;
        a[v][u] = 1;
    } else {
        a[v][u] = -1;
        a[u][v] = 1;
    }
    return a[u][v];
}

int solve(int l, int r) {
    if (l == r) return id[l];
    int m = l + r >> 1;
    int p1 = solve(l, m);
    int p2 = solve(m + 1, r);
    if (p1 == -1 && p2 == -1) return -1;
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (fight(p1, p2) == -1) return p1;
    return p2;
}

pair<int, int> b[3];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        memset(a, 0, sizeof a);
        if (n == 3) {
            b[0] = {1, 2};
            b[1] = {3, 4};
            b[2] = {5, 6};
            for (int i = 0; i < 3; i++) {
                if (fight(b[i].first, b[i].second) == 1) swap(b[i].first, b[i].second);
            }
            for (int i = 1; i >= 0; i--) {
                if (fight(b[i].first, b[i + 1].first) == 1) swap(b[i], b[i + 1]);
            }
            b[0].first = b[0].second;
            b[0].second = -1;
            if (fight(b[1].first, b[2].first) == 1) swap(b[1], b[2]);
            if (fight(b[0].first, b[1].first) == 1) {
                b[1].first = b[1].second;
                b[1].second = -1;
                int now = fight(b[0].first, b[1].first) == -1 ? b[0].first : b[1].first;
                fight(now, b[2].first);
            }
        } else {
            int sz = 1;
            while (sz < n * 2) sz *= 2;
            fill(id + 1, id + sz + 1, -1);
            for (int i = 1; i <= n * 2; i++) id[i] = i;
            for (int i = 1; i <= n; i++) {
                int worst = solve(1, sz);
                id[worst] = -1;
            }
        }
        cout << "!" << endl << flush;
    }
    return 0;
}