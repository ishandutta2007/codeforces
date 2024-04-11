#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll INF = 2e18;
const int INFi = 2e9;

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    fenwick f;
    f.build(n);
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return a[i] > a[j];
    });
    int ans = 0;
    range(i, n) {
        if (a[i] >= 0) {
            ans++;
            f.upd(i, a[i]);
        }
    }
    set<int> mns;
    ll mn = INF;
    for(int i = n - 1; i >= 0; --i) {
        if (f.get(i) < mn) {
            mns.insert(i);
            mn = f.get(i);
        }
    }
    for(auto &i : ord) {
        if (a[i] >= 0) continue;
        auto it = mns.lower_bound(i);
        int j = (*it);
        if (f.get(j) + a[i] < 0) continue;
        f.upd(i, a[i]);
        vector<int> del;
        while(it != mns.begin()) {
            it--;
            int j2 = (*it);
            if (f.get(j2) >= f.get(j)) {
                del.push_back(j2);
            } else {
                break;
            }
        }
        ans++;
        for(auto &j2 : del) mns.erase(j2);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}