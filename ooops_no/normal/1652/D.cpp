#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

const int N = 2e5 + 10, MOD = 998244353;
vector<vector<int>> g[N];
vector<pair<int,int>> arr[N];
vector<int> cnt(N);
vector<int> bst(N);
vector<int> inv(N);

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return (a * b % MOD);
}

int binpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        int g = binpow(a, n / 2);
        return mul(g, g);
    } else {
        return mul(binpow(a, n - 1), a);
    }
}

void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to[0] != p) {
            for (auto t : arr[to[1]]) {
                cnt[t.first] -= t.second;
                bst[t.first] = max(bst[t.first], -cnt[t.first]);
            }
            for (auto t : arr[to[2]]) {
                cnt[t.first] += t.second;
                bst[t.first] = max(bst[t.first], -cnt[t.first]);
            }
            dfs(to[0], v);
            for (auto t : arr[to[1]]) {
                cnt[t.first] += t.second;
            }
            for (auto t : arr[to[2]]) {
                cnt[t.first] -= t.second;
            }
        }
    }
}

int ans = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void zhfs(int v, int p, int now_val) {
    ans = add(ans, now_val);
    for (auto to : g[v]) {
        if (to[0] != p) {
            zhfs(to[0], v, mul(inv[to[1]], mul(now_val, to[2])));
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    for (int i = 0; i < N; i++) {
        inv[i] = binpow(i, MOD - 2);
    }
    for (int i = 2; i < N; i++) {
        int now = i;
        for (int j = 2; j * j <= i; j++) {
            if (now % j == 0) {
                int cnt = 0;
                while (now % j == 0) {
                    cnt++;
                    now /= j;
                }
                arr[i].pb({j, cnt});
            }
        }
        if (now > 1) {
            arr[i].pb({now, 1});
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        vector<int> pr;
        for (int i = 0; i < n - 1; i++) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            a--, b--;
            int g1 = gcd(x, y);
            x /= g1, y /= g1;
            g[a].pb({b, x, y});
            g[b].pb({a, y, x});
            for (auto to : arr[x]) {
                pr.pb(to.first);
            }
            for (auto to : arr[y]) {
                pr.pb(to.first);
            }
        }
        sort(pr.begin(), pr.end());
        pr.erase(unique(pr.begin(), pr.end()), pr.end());
        dfs(0, -1);
        ans = 0;
        int res = 1;
        for (auto i : pr) {
            res = mul(res, binpow(i, bst[i]));
            bst[i] = 0;
        }
        zhfs(0, -1, res);
        cout << ans << '\n';
    }
    return 0;
}