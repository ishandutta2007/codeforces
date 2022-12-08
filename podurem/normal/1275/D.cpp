#include <bits/stdc++.h>

using namespace std;
#ifdef SIR
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define err(...) 42
#endif
typedef long long ll;

#define multitest false

void solve();
int main() {
#ifdef SIR
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multitest) cin >> t;
    for (int it = 1; it <= t; ++it) solve();
    return 0;
}

// CONSTANTS HERE

void upd(multiset<int> &a, int x) {
    a.insert(x);
}

void mrg(multiset<int> &a, multiset<int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (int i : b) a.insert(i);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int cur = 0;
    vector<int> t(n);
    for (int &i : t) cin >> i;

    map<int, int> cnt;
    map<int, ll> S;
    map<int, multiset<int>> mx;
    for (int i = 0; i < n; ++i) {
        S[a[i]] += t[i];
        upd(mx[a[i]], t[i]);
        cnt[a[i]]++;
    }

    ll ans = 0;
    while (true) {
        auto it = cnt.lower_bound(cur);
        if (it == cnt.end()) break;
        cur = it->first;
        if (cnt[cur] > 1) {
            ans += S[cur] - *mx[cur].rbegin();
            S[cur + 1] += S[cur] - *mx[cur].rbegin();
            cnt[cur + 1] += cnt[cur] - 1;
            mx[cur].erase(--mx[cur].end());
            mrg(mx[cur + 1], mx[cur]);
        }
        ++cur;
    }
    cout << ans << "\n";
}