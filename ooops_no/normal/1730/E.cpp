#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 5e5 + 10, M = 1e6 + 10;
int a[N], cnt[M], q[N], mx[N], mn[N];
vector<int> del[M];
ll ans = 0;

void solve(int l, int r) {
    if (l == r) {
        ans++;
        return;
    }
    int m = (l + r) / 2;
    solve(l, m), solve(m + 1, r);
    mx[m] = mn[m] = a[m];
    mx[m + 1] = mn[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; ++i) {
        mx[i] = max(mx[i - 1], a[i]);
        mn[i] = min(mn[i - 1], a[i]);
    }
    for (int i = m - 1; i >= l; --i) {
        mx[i] = max(mx[i + 1], a[i]);
        mn[i] = min(mn[i + 1], a[i]);
    }
    int pos = m + 1, sz = 0, ind = 0;
    for (int i = m; i >= l; --i) {
        while (pos <= r && mx[pos] <= mx[i]) {
            cnt[mn[pos]]++;
            q[sz++] = mn[pos];
            pos++;
        }
        while (ind < sz && q[ind] >= mn[i]) {
            cnt[q[ind]]--;
            ind++;
        }
        if (mx[i] % mn[i] == 0) {
            ans += ind;
        }
        for (auto to : del[mx[i]]) {
            ans += cnt[to];
        }
    }
    while (ind < sz) {
        cnt[q[ind]]--;
        ind++;
    }
    pos = m, sz = 0, ind = 0;
    for (int i = m + 1; i <= r; ++i) {
        while (pos >= l && mx[pos] < mx[i]) {
            cnt[mn[pos]]++;
            q[sz++] = mn[pos];
            pos--;
        }
        while (ind < sz && q[ind] >= mn[i]) {
            cnt[q[ind]]--;
            ind++;
        }
        if (mx[i] % mn[i] == 0) {
            ans += ind;
        }
        for (auto to : del[mx[i]]) {
            ans += cnt[to];
        }
    }
    while (ind < sz) {
        cnt[q[ind]]--;
        ind++;
    }
}

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int mx = 0;
    for (int i = 1; i < M; ++i) {
        for (int j = i; j < M; j += i) {
            del[j].pb(i);
        }
        mx = max(mx, (int)del[i].size());
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(0, n - 1);
        cout << ans << endl;
    }
    return 0;
}