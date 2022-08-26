#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 7e5 + 100;
const int md = 998244353;
const ll INF = 2e18;

int a[maxN];
int el[maxN];
int cnt[maxN];
int n;

void build() {
    range(i, n) {
        el[i + n] = a[i];
        cnt[i + n] = 1;
    }
    for (int i = n - 1; i >= 1; --i) {
        if (el[i << 1] == el[i << 1 | 1]) {
            el[i] = el[i << 1];
            cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
            continue;
        }
        if (cnt[i << 1] > cnt[i << 1 | 1]) {
            el[i] = el[i << 1];
            cnt[i] = cnt[i << 1] - cnt[i << 1 | 1];
        } else {
            el[i] = el[i << 1 | 1];
            cnt[i] = cnt[i << 1 | 1] - cnt[i << 1];
        }
    }
}

int get(int l, int r) {
    l += n;
    r += n;
    int el1 = 0, cnt1 = 0;
    while (l < r) {
        if (l & 1) {
            if (el[l] == el1) {
                cnt1 += cnt[l];
            } else if (cnt[l] > cnt1) {
                el1 = el[l];
                cnt1 = cnt[l] - cnt1;
            } else {
                cnt1 -= cnt[l];
            }
            l++;
        }
        if (r & 1) {
            r--;
            if (el[r] == el1) {
                cnt1 += cnt[r];
            } else if (cnt[r] > cnt1) {
                el1 = el[r];
                cnt1 = cnt[r] - cnt1;
            } else {
                cnt1 -= cnt[r];
            }
        }
        l >>= 1;
        r >>= 1;
    }
    return el1;
}

void solve() {
    int q;
    cin >> n >> q;
    vector<vector<int>> pos(n + 1);
    range(i, n) cin >> a[i];
    range(i, n) pos[a[i]].push_back(i);
    build();
    range(_, q) {
        int l, r;
        cin >> l >> r;
        l--;
        int len = r - l;
        int x = get(l, r);
        int k = lower_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
        int t = len - k;
        // t * 2 + 1
        cout << max(1, len - t * 2) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}