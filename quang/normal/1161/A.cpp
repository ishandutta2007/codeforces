#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
int l[N], r[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        l[i] = k + 1;
        r[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        l[u] = min(l[u], i);
        r[u] = max(r[u], i);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (r[i] == 0) res++;
        if (i < n && r[i + 1] < l[i]) {
            res++;
        }
        if (i < n && r[i] < l[i + 1]) res++;
    }
    cout << res << endl;
    return 0;
}