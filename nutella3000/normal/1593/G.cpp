#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);


const int inf = 1e9 + 7;

int n;
string s;

int N;
vector<int> type, cnt;

pii merge(pii a, pii b) {
    int fi = a.fi + a.se & 1;
    if (fi == b.fi) {
        return {a.fi, a.se + b.se};
    }
    return {a.se > b.se ? a.fi : b.fi + a.se & 1, abs(b.se - a.se)};
}


pii segget(int l, int r, int v = 1, int tl = 0, int tr = N) {
    if (tl >= r || tr <= l) return {0, 0};
    if (tl >= l && tr <= r) return {type[v], cnt[v]};
    int mid = (tl + tr) / 2;
    return merge(segget(l, r, v * 2, tl, mid), segget(l, r, v * 2 + 1, mid, tr));
}

void run() {
    int q;
    cin >> s >> q;
    n = size(s);
    N = 1 << 32 - __builtin_clz(n);
    type.clear();
    cnt.clear();
    type.resize(2 * N);
    cnt.resize(2 * N);
    for (int i = 0; i < n; ++i) {
        type[N + i] = (s[i] == '[' || s[i] == ']');
        cnt[N + i] = 1;
    }
    for (int i = N - 1; i >= 0; --i) {
        pii q = merge(mp(type[i * 2], cnt[i * 2]), mp(type[i * 2 + 1], cnt[i * 2 + 1]));
        type[i] = q.fi;
        cnt[i] = q.se;
    }
    while (q--) {
        int l, r; cin >> l >> r; --l;
        auto q = segget(l, r);
        cout << q.se / 2 << '\n';
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}