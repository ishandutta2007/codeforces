#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int mod = 998244353;

int n, k;
int a[N];
int f[N][N + N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    f[0][N] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < N + N; ++j) {
            if(!f[i][j]) continue;
            int p = i + 1, q = (i + 1) % n + 1;
            if(a[p] == a[q]) {
                f[i + 1][j] += 1LL * f[i][j] * k % mod;
                f[i + 1][j] %= mod;
            }
            else {
                f[i + 1][j] += 1LL * f[i][j] * (k - 2) % mod;
                f[i + 1][j] %= mod;
                f[i + 1][j + 1] += f[i][j];
                f[i + 1][j + 1] %= mod;
                f[i + 1][j - 1] += f[i][j];
                f[i + 1][j - 1] %= mod;
            }
        }
    }

    int ans = 0;
    for(int i = N + 1; i < N + N; ++i) {
        ans += f[n][i];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}