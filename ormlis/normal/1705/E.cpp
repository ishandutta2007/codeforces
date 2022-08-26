#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 3e5 + 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    set<pair<int, int>> segs;
    vi cnt(maxN);
    rep(i, n) cnt[a[i]]++;
    int l = -1;
    for (int i = 1; i < maxN; ++i) {
        if (cnt[i] >= 2) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
        }
        if (cnt[i] == 1) {
            if (l == -1) l = i;
        } else if (l != -1) {
            segs.insert({l, i - 1});
            l = -1;
        }
    }
    auto get_next = [&] (int x) {
        pair<int, int> kek = {x + 1, -1};
        auto it = segs.lower_bound(kek);
        if (it != segs.begin()) {
            auto seg = *prev(it);
            assert(seg.first <= x);
            if (seg.second >= x) return seg;
        }
        assert(it != segs.end());
        auto seg = *it;
        assert(seg.first > x);
        return seg;
    };
    rep(_, q) {
        int i, x; cin >> i >> x;
        i--;
        auto seg = get_next(a[i]);
        if (seg.first <= a[i] && a[i] <= seg.second) {
            segs.erase(seg);
            if (seg.first < a[i]) segs.insert({seg.first, a[i] - 1});
            if (seg.second > a[i]) segs.insert({a[i] + 1, seg.second});
        } else {
            auto val = get_next(a[i] - 1);
            segs.erase(seg);
            assert(seg.first > a[i]);
            if (seg.first < seg.second) {
                segs.insert({seg.first + 1, seg.second});
            }
            int R = seg.first - 1;
            int L = a[i];
            if (val.second == a[i] - 1) {
                segs.erase(val);
                L = val.first;
            }
            segs.insert({L, R});
        }
        a[i] = x;
        while(true) {
            if (segs.empty() || segs.rbegin()->second + 1 < x) {
                segs.insert({x, x});
                break;
            } else if (segs.rbegin()->second + 1 == x) {
                seg = *prev(segs.end());
                segs.erase(seg);
                seg.second = x;
                segs.insert(seg);
                break;
            } else {
                assert(x <= segs.rbegin()->second);
                seg = get_next(x);
                if (seg.first <= x && x <= seg.second) {
                    segs.erase(seg);
                    if (seg.first < x) {
                        segs.insert({seg.first, x - 1});
                    }
                    x = seg.second + 1;
                    continue;
                }
                int L = x;
                int R = x;
                auto val = get_next(x - 1);
                if (val.second == x - 1) {
                    L = val.first;
                    segs.erase(val);
                }
                if (seg.first == x + 1) {
                    R = seg.second;
                    segs.erase(seg);
                }
                segs.insert({L, R});
                break;
            }
        }
        cout << segs.rbegin()->second << '\n';
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}