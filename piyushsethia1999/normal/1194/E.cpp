#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

const int N = 10003;
int seg[N * 2];

void build() {
    for (int i = N - 1; i > 0; --i) seg[i] = seg[i << 1] + seg[(i << 1) | 1];
}

void update(int i, int val) {
    for(seg[i += N] += val; i > 1; i >>= 1) seg[i >> 1] = seg[i] + seg[i ^ 1];
}

int query(int l, int r) {
    r++; int a = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (r & 1) a += seg[--r];
        if (l & 1) a += seg[l++];
    }
    return a;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n; cin >> n;
    std::vector<pair<int, int>> v[10004];
    std::vector<pair<int, pair<int, int>> > h;
    for (int i = 0; i < n; ++i) {
        int x1; cin >> x1;
        int y1; cin >> y1;
        int x2; cin >> x2;
        int y2; cin >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2) {
            v[x1 + 5000].pb(y1 + 5000, y2 + 5000);
        } else {
            h.push_back({y1 + 5000, {x1 + 5000, x2 + 5000}});
        }
    }
    long long ans = 0;
    for (int x = 0; x <= 10000; ++x) {
        if (v[x].empty()) continue;
        std::vector<pair<int, int> > en;
        for (int i = 0; i < h.size(); ++i) {
            if (h[i].se.fi <= x && h[i].se.se > x) {
                en.pb(h[i].se.se, h[i].fi);
                update(h[i].fi, 1);
            } 
        }
        sort(en.begin(), en.end());
        int in = 0;
        for (int x2 = x + 1; x2 <= 10001; ++x2) {
            if (v[x2].empty()) continue;
            while (in < en.size() && en[in].fi < x2) {
                update(en[in].se, -1);
                in++;
            } 
            for (int i = 0; i < v[x].size(); ++i) {
                for (int j = 0; j < v[x2].size(); ++j) {
                    int y1 = max(v[x][i].first, v[x2][j].first);
                    int y2 = min(v[x][i].second, v[x2][j].second);
                    if (y1 < y2) {
                        long long an = query(y1, y2);
                        ans += (an * (an - 1ll)) / 2ll;
                    } 
                }
            }
        }
        while (in < en.size()) {
            update(en[in].se, -1);
            in++;
        } 
    }
    cout << ans;
}