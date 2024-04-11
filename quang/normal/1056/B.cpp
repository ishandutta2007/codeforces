#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int cnt[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int u = n / m;
    for (int i = 1; i <= m; i++) {
        cnt[i * i % m] += u;
    }
    n %= m;
    for (int i = 1; i <= n; i++) {
        cnt[i * i % m]++;
    }
    long long res = 0;
    for (int i = 0; i < m; i++) {
        res += 1ll * cnt[i] * cnt[(m - i) % m];
    }
    cout << res << endl;
    return 0;
}