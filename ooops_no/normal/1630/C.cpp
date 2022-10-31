#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

struct st {
    vector<int> t;
    st (int n) {
        t.resize(4 * n);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -1;
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), go(n), last(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    st t(n);
    for (int i = n - 1; i >= 0; i--) {
        go[i] = last[a[i]];
        if (last[a[i]] == -1) last[a[i]] = i;
        t.update(1, 0, n - 1, i, last[a[i]]);
    }
    int r = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (i >= r) {
            r = max(r, go[i]);
        } else {
            int mx = t.get(1, 0, n - 1, i + 1, r - 1);
            if (max(r, mx) >= go[i]) {
                ans++;
            } else {
                r = max(r, go[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}