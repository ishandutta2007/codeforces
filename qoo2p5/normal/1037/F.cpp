#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

const int N = (int) 1 << 20;

int n, k;
int a[N];
int tree[2 * N];

int get(int i, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return tree[i];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * i + 1, tl, tm, l, r), get(2 * i + 2, tm, tr, l, r));
}

int get(int l, int r) {
    return get(0, 0, N, l, r + 1);
}

int cool(int i, int tl, int tr, int l, int r, int x) {
    if (tl >= r || tr <= l) {
        return N;
    }
    if (tree[i] <= x) {
        return N;
    }
    if (tl == tr - 1) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int res = cool(2 * i + 1, tl, tm, l, r, x);
    if (res == N) {
        return cool(2 * i + 2, tm, tr, l, r, x);
    }
    return res;
}
#define int long long

int cool(int l, int r, int x) {
    return cool(0, 0, N, l, r + 1, x);
}

int dp[N];
const int MOD = (int) 1e9 + 7;

int f(vector<int> a) {
    if ((int) a.size() < k) {
        return 0;
    }
    vector<int> b;
    int ans = 0;
    for (int i = 0; i < (int) a.size() - k + 1; i++) {
        int temp = a[i];
        for (int j = i; j < i + k; j++) {
            temp = max(temp, a[j]);
        }
        b.push_back(temp);
        ans = (ans + temp) % MOD;
    }
    return (ans + f(b)) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tree[N + i - 1] = a[i];
    }
    for (int i = N - 2; i >= 0; i--) {
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i + k - 2 >= n) {
            continue;
        }

        int mx = get(i, i + k - 2);
        int nxt = cool(i + k - 1, N - 1, mx);
        if (nxt == N) {
            dp[i] = (int) (mx * 1LL * ((n - i) / (k - 1)) % MOD);
        } else {
            int x = (nxt - i) / (k - 1);
            int ps = i + (k - 1) * x;
            dp[i] = (int) ((mx * 1LL * x + dp[ps]) % MOD);
        }

        if (i + k - 1 >= n) {
            continue;
        }

        mx = get(i, i + k - 1);
        nxt = cool(i + k, N - 1, mx);
        if (nxt == N) {
            ans += (int) (mx * 1LL * (1 + (n - i - k) / (k - 1)) % MOD);
            ans %= MOD;
        } else {
            int x = (nxt - i - k) / (k - 1);
            int ps = i + k + x * (k - 1);
            assert(ps < n);
            if (ps < n) {
                ans += dp[ps];
                ans %= MOD;
            }
            ans += (int) (mx * 1LL * (1 + x) % MOD);
            ans %= MOD;
        }
    }

    cout << ans << "\n";


    return 0;
}