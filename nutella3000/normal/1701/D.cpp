#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

struct seg {
    int l, r, id;
    seg() {}
    seg(int l, int r, int id) : l(l), r(r), id(id) {}

    bool operator< (const seg& a) const {
        return l < a.l;
    }
};

void run() {
    int n; cin >> n;

    vector<seg> a(n);

    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        int k1 = i / (v+1);
        int k2 = (v == 0 ? inf : i / v);

        while (!k1 || i/k1 != v) ++k1;
        while (i/k2 != v) --k2;

        a[i-1] = {k1, k2, i-1};
    }
    sort(all(a));

    vector<int> b(n);

    auto op = [&](seg v1, seg v2) { return mp(v1.r, v1.id) < mp(v2.r, v2.id); };
    set<seg, decltype(op)> so(op);

    for (int i = 0, id = 1; id <= n; ++id) {
        while (i < n && a[i].l <= id)
            so.emplace(a[i++]);
        b[so.begin()->id] = id;
        so.erase(so.begin());
    }

    for (auto i : b)
        cout << i << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}