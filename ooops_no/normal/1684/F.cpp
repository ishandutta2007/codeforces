#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

int solve(int n, int m, vector<int> a, vector<pair<int,int>> u) {
    vector<int> mx(n, -1), mx_seg(n, -1), cnt(n);
    vector<pair<int,int>> seg;
    vector<bool> have_seg(n);
    map<int, deque<int>> ind;
    for (int i = 0; i < n; i++) {
        ind[a[i]].pb(i);
    }
    for (int i = 0; i < m; i++) {
        int l = u[i].first, r = u[i].second;
        mx[l] = max(mx[l], r);
    }
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i], mx[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        ind[a[i]].pop_front();
        if (ind[a[i]].size() > 0) {
            int j = ind[a[i]][0];
            if (mx[i] >= j) {
                seg.pb({i, j});
                have_seg[i] = 1;
                cnt[j]++;
                int l = 0, r = ind[a[i]].size();
                while (r - l > 1) {
                    int mid = (r + l) / 2;
                    if (mx[i] >= ind[a[i]][mid]) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                j = ind[a[i]][l];
                mx_seg[i] = max(mx_seg[i], j);
            }
        }
    }
    if (seg.size() == 0) {
        return 0;
    }
    int ans = n, mx_ind = -1;
    for (int i = 1; i < n; i++) {
        mx_seg[i] = max(mx_seg[i], mx_seg[i - 1]);
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (have_seg[i]) {
            mx_ind = max(mx_ind, i);
        }
        if (i > 0 && cnt[i - 1] > 0) continue;
        int need = max(i, mx_ind);
        if (i > 0) {
            need = max(need, mx_seg[i - 1]);
        }
        ans = min(ans, need - i + 1);
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<pair<int,int>> u(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> u[i].first >> u[i].second;
            u[i].first--, u[i].second--;
        }
        cout << solve(n, m, a, u) << endl;
    }
    return 0;
}