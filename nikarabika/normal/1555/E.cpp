#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 1e6 + 10;
int seg[maxn << 2],
    laz[maxn << 2],
    ord[maxn],
    le[maxn],
    ri[maxn],
    we[maxn];
int n, m;

void add(int val, int st, int en, int l = 0, int r = m, int id = 1) {
//    if (tim[id] < curtime) {
//        seg[id] = laz[id] = 0;
//        tim[id] = curtime;
//    }
    if (st >= r or en <= l)
        return;
    if (st <= l and r <= en) {
        seg[id] += val;
        laz[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    add(val, st, en, l, mid, id << 1 | 0);
    add(val, st, en, mid, r, id << 1 | 1);
    seg[id] = min(seg[id << 1 | 0], seg[id << 1 | 1]) + laz[id];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m--;
    for (int i = 0; i < n; i++) {
        cin >> le[i] >> ri[i] >> we[i];
        le[i]--, ri[i]--;
    }

    iota(ord, ord + n, 0);
    sort(ord, ord + n, [](int i, int j) -> bool { return we[i] < we[j]; });

    int ans = 1e6;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        add(+1, le[ord[i]], ri[ord[i]]);
        while (seg[1] > 0 and ptr <= i) {
            add(-1, le[ord[ptr]], ri[ord[ptr]]);
            ptr++;
        }
        if (ptr - 1 >= 0)
            smin(ans, we[ord[i]] - we[ord[ptr - 1]]);
    }
    cout << ans << '\n';
    return 0;
}