#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N], b[N];
int id[N];

bool cmp(int u, int v) {
    return a[u] - b[u] > a[v] - b[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int now = id[i];
        res += 1ll * a[now] * (i - 1) + 1ll * b[now] * (n - i);
    }
    cout << res << endl;
    return 0;
}