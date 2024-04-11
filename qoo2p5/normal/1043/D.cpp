#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

// Solution

const int N = (int) 1e5 + 123;
const int M = 11;

int n, m;
int a[M][N];
int pos[M][N];

int p[N], cnt[N];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return (p[v] = get(p[v]));
}

void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return;
    }
    p[u] = v;
    cnt[v] += cnt[u];
}

void run() {
    for (int i = 0; i < N; i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            pos[i][a[i][j]] = j;
        }
    }
    for (int j = 0; j < n; j++) {
        if (pos[0][j] == n - 1) {
            continue;
        }
        bool ok = true;
        int nxt = a[0][pos[0][j] + 1];
        for (int i = 1; i < m; i++) {
            if (pos[i][j] == n - 1) {
                ok = false;
                break;
            }
            if (a[i][pos[i][j] + 1] != nxt) {
                ok = false;
                break;
            }
        }
        if (ok) {
            unite(j, nxt);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != i) {
            continue;
        }
        ll c = cnt[i];
        ans += c * (c + 1) / 2;
    }
    cout << ans << "\n";
}