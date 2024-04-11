#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 1e6 + 10, M = 2e7 + 10;
vector<int> res(30), was(M);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= m; j++) {
            if (!was[i * j]) {
                was[i * j] = 1;
                cnt++;
            }
        }
        res[i] = cnt;
    }
    fill(was.begin(), was.end(), 0);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (was[i]) continue;
        int now = i, cnt = 0;
        while (now <= n) {
            was[now] = 1;
            cnt++;
            now *= i;
        }
        ans += res[cnt];
    }
    cout << ans + 1 << endl;
    return 0;
}