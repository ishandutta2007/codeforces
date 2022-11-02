#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int MOD = 998244353, N = 1e5 + 10;
int k;
vector<int> g[N];

int mul(int a, int b) {
    return (a * b % MOD);
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int g = binpow(a, n / 2);
        return mul(g, g);
    } else {
        return mul(binpow(a, n - 1), a);
    }
}

int dfs(int v, int p) {
    int sum = 0;
    for (auto to : g[v]) {
        if (to != p) {
            int res = dfs(to, v);
            if (res == -1) return -1;
            sum += res;
        }
    }
    sum %= k;
    if (sum == 0) return 1;
    if (sum + 1 == k) {
        return 0;
    }
    return -1;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<int> cnt(n + 1);
        cnt[1] = binpow(2, n - 1);
        for (int i = 2; i <= n - 1; i++) {
            if ((n - 1) % i == 0) {
                k = i;
                int res = dfs(0, -1);
                if (res == 1) {
                    cnt[i]++;
                }
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 2 * i; j <= n - 1; j += i) {
                cnt[i] = sub(cnt[i], cnt[j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << cnt[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}