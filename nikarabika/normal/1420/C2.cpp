//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 3e5 + 10;
const LL INF = 1e18;
int n;

struct node {
    LL maxeven, maxodd;
    LL mineven, minodd;
} seg[maxn * 4];

void modify(int idx, LL val, int l = 0, int r = n, int id = 1) {
    if (idx < l or r <= idx)
        return;
    if (r - l == 1) {
        seg[id] = {0, val, 0, val};
        return;
    }
    int mid = (l + r) >> 1;
    modify(idx, val, l, mid, id << 1 | 0);
    modify(idx, val, mid, r, id << 1 | 1);

    int le = id << 1 | 0;
    int ri = id << 1 | 1;

    seg[id].maxeven = max(seg[le].maxeven + seg[ri].maxeven,
            seg[le].maxodd - seg[ri].minodd);
    seg[id].maxodd = max(seg[le].maxeven + seg[ri].maxodd,
            seg[le].maxodd - seg[ri].mineven);

    seg[id].mineven = min(seg[le].mineven + seg[ri].mineven,
            seg[le].minodd - seg[ri].maxodd);
    seg[id].minodd = min(seg[le].mineven + seg[ri].minodd,
            seg[le].minodd - seg[ri].maxeven);
}

int solve() {
    int q;
    cin >> n >> q;
    int a[n];
    LL even = 0;
    LL odd = -1e18;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        modify(i, x);
        a[i] = x;
    }
    cout << max(seg[1].maxeven, seg[1].maxodd) << '\n';
    while (q--) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        int ai = a[fi];
        int aj = a[se];
        modify(fi, aj);
        modify(se, ai);
        swap(a[fi], a[se]);
        cout << max(seg[1].maxeven, seg[1].maxodd) << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}