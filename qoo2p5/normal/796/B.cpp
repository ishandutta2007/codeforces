#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e6 + 123;

int n, m, k;
bool a[N];

void run() {
    cin >> n >> m >> k;
    int pos = 1;
    for (int i = 0; i < m; i++) {
        int h;
        cin >> h;
        a[h] = 1;
    }
    bool fixed = a[1];
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        if (fixed) continue;
        if (pos == u) pos = v;
        else if (pos == v) pos = u;
        fixed |= a[pos];
    }
    cout << pos << "\n";
}