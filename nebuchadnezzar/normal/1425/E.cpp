#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}

ll solve(vector<ll> A, vector<ll> D, int n, int k) {
    ll ans = 0;
    ans = max(ans, A.back() - D.back());
    if (k == 0) {
        ll add = accumulate(A.begin(), A.end(), 0ll);
        for (int i = 0; i < n; i++) {
            ans = max(ans, add - D[i]);
            add -= A[i];
        }
    } else if (k == 1) {
        {
            vector<ll> T(n + 1);
            ll p = 0;
            for (int i = n - 1; i >= 0; i--) {
                p += A[i];
                T[i] = max(T[i + 1], p - D[i]);
            }

            ll cur = D[0];
            ll sum = 0;

            for (int i = 0; i + 1 < n; i++) {
                cur = min(cur, D[i]);
                sum += A[i];
                ans = max(ans, max(sum - cur, 0ll) + T[i + 1]);
            }
        }

        {
            ll sum = accumulate(A.begin(), A.end(), 0ll);
            for (int i = 1; i < n; i++) {
                ans = max(ans, sum - A[i] - D[0] + max(0ll, A[i] - D[i]));
            }
        }
    } else {
        ll sum = accumulate(A.begin(), A.end(), 0ll);
        ans = max(ans, sum - *min_element(D.begin(), D.end() - 1));

        ans = max(ans, solve(A, D, n, 0));
        ans = max(ans, solve(A, D, n, 1));
    }
    return ans;
}

ll calc(vector<ll> A, vector<ll> D, vector<int> pos, int n) {
    ll ans = 0;
    for (int msk = 0; msk < (1 << n); msk++) {
        vector<int> used(n);
        ll res = 0;
        for (int i = 0; i < n; i++) if ((msk >> i) & 1) {
            res -= D[i];
            for (int q = i; q != -1 && !used[q]; q = pos[q]) {
                res += A[q];
                used[q] = 1;
            }
        }
        ans = max(ans, res);
    }
    return ans;
}

ll slow(vector<ll> A, vector<ll> D, int n, int k) {
    assert(k == 1);

    vector<int> pos(n, -1);
    for (int i = 0; i + 1 < n; i++) pos[i] = i + 1;

    ll ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int t = 0; t < n; t++) if (t != i && t != pos[i]) {
            auto cur = pos;
            cur[i] = t;
            ans = max(ans, calc(A, D, cur, n));
        }
    }
    return ans;
}

void stress() {
    for (int test = 0; test < 100; test++) {
        mt19937 rnd(test);

        int n = 4, k = 1;
        vector<ll> A(n), D(n);
        for (int i = 0; i < n; i++) A[i] = rnd() % 10 + 1;
        for (int i = 0; i < n; i++) D[i] = rnd() % 10 + 1;

        ll ans1 = solve(A, D, n, k);
        ll ans2 = slow(A, D, n, k);

        if (ans1 != ans2) {
            cerr << ans1 << " " << ans2 << "\n";
            for (int x : A) cerr << x << " "; cerr << "\n";
            for (int x : D) cerr << x << " "; cerr << "\n";
            solve(A, D, n, k);
            slow(A, D, n, k);
            cerr << "fail " << test << "\n";
            return;
        }
        cerr << "ok " << test << "\n";
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> A(n), D(n);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> D[i];

    ll ans = solve(A, D, n, k);

    cout << ans << "\n";
}