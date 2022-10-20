#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 998244353;
const int K = sqrt(N);
// const int K = 2;
// const int N = 1000;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, k;
int a[N];
pair<int, int> last[N];
int dp[N];
int d[N];

struct Block {
    int tot = 0, delta = 0;
    int cnt[N];

    Block() {
        memset(cnt, 0, sizeof cnt);
    }

    void add(int d, int v) {
        if (d > k + 1) return;
        cnt[d] = ::add(cnt[d], v);
        if (d + delta <= k) tot = ::add(tot, v);
    }

    void update(int flag) {
        if (flag == 1) {
            if (k >= delta) tot = sub(tot, cnt[k - delta]);
            delta++;
        } else {
            delta--;
            if (k >= delta) tot = ::add(tot, cnt[k - delta]);
        }
    }
} b[N / K + 10];

void addVal(int u, int delta) {
    int pos = u / K;
    int val = delta == 1 ? dp[u] : sub(0, dp[u]);
    b[pos].add(d[u], val);       
}

void update(int l, int r, int flag) {
    int posL = l / K;
    int posR = r / K;
    if (posL == posR) {
        for (int i = l; i <= r; i++) {
            addVal(i, -1);
            d[i] += flag;
            addVal(i, 1);
        }
        return;
    }
    for (int i = l; i < K * (posL + 1); i++) {
        addVal(i, -1);
        d[i] += flag;
        addVal(i, 1);
    }
    for (int i = posL + 1; i < posR; i++) {
        b[i].update(flag);
    }
    for (int i = K * posR; i <= r; i++) {
        addVal(i, -1);
        d[i] += flag;
        addVal(i, 1);
    }
}

int get(int u) {
    int res = 0;
    for (int i = 0; i * K <= u; i++) {
        res = add(res, b[i].tot);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(last, -1, sizeof last);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        addVal(i, 1);
        update(last[a[i]].first + 1, i, 1);
        if (last[a[i]].first != -1) update(last[a[i]].second + 1, last[a[i]].first, -1);

        last[a[i]].second = last[a[i]].first;
        last[a[i]].first = i;
        dp[i + 1] = get(i);

        // cout << "step " << i << endl;
        // cout << i << ' ' << dp[i + 1] << endl;
        // for (int j = 0; j <= n / K; j++) cout << b[j].tot << ' ' ;
        //     cout << endl;
    }
    cout << dp[n] << endl;
    return 0;
}