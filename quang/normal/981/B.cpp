#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
map<int, int> a;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u] = max(a[u], v);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u] = max(a[u], v);
    }
    long long res = 0ll;
    for (pair<int, int> u : a) {
        res += u.second;
    }
    cout << res << endl;
    return 0;
}