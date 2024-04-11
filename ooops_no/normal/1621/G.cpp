#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7, INF = 1e9;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return (1ll * a * b % MOD);
}

struct Fenwick {
    vector<int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] = add(t[i], d);
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans = add(ans, t[r]);
        }
        return ans;
    }
    int get(int l, int r) {
        return sub(get(r), get(l - 1));
    }
};

int solve(int n, vector<int> a) {
    int ans = 0;
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> ind;
    for (int i = 0; i < n; i++) {
        ind[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = ind[a[i]]--;
    }
    Fenwick f(n), f_rev(n);
    vector<int> dp(n), dp_rev(n), cnt(n);
    vector<bool> good(n);
    for (int i = 0; i < n; i++) {
        int res = add(1, f.get(a[i] - 1));
        dp[i] = res;
        f.inc(a[i], res);
    }
    for (int i = n - 1; i >= 0; i--) {
        int res = add(1, f_rev.get(a[i] + 1, n - 1));
        dp_rev[i] = res;
        f_rev.inc(a[i], res);
    }
    int last = -1;
    vector<pair<int,int>> u;
    for (int i = n - 1; i >= 0; i--) {
        if (last == -1 || a[i] > a[last]) {
            //add index i
            u.pb({a[i], i});
            last = i;
        }
    }
    u.pb({INF, -1});
    int m = u.size();
    vector<vector<int>> arr(m);
    for (int i = n - 1; i >= 0; i--) {
        int j = lower_bound(u.begin(), u.end(), make_pair(a[i], INF)) - u.begin();
        if (i < u[j].second) {
            arr[j].pb(i);
            good[i] = 1;
        }
    }
    Fenwick t(n);
    for (int i = 0; i < m - 1; i++) {
        map<int,int> mp;
        for (auto j : arr[i]) {
            int val = add(1, t.get(a[j] + 1, n - 1));
            cnt[j] = val;
            t.inc(a[j], val);
        }
        for (auto j : arr[i]) {
            t.inc(a[j], sub(MOD, cnt[j]));
        }
    }
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans = add(ans, mul(dp[i], sub(dp_rev[i], cnt[i])));
        }
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}