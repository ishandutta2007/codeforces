#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int bd = 18, bdv = 1 << bd;

int n;
map <int, int> mp;
vector <int> arrx;

int rsq[bdv * 2];

int segtree_plus(int pos) {
    pos += bdv;
    rsq[pos] = 1;
    pos /= 2;
    while (pos) {
        rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
        pos /= 2;
    }
    return 0;
}

int segtree_sum(int v, int vl, int vr, int l, int r) {
    if (r < vl || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[v];
    }
    int vm = (vl + vr) / 2;
    return segtree_sum(v * 2, vl, vm, l, r) + segtree_sum(v * 2 + 1, vm + 1, vr, l, r);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arrx.puba(a);
        arrx.puba(b);
        if (!mp.count(a)) {
            mp[a] = a;
        }
        if (!mp.count(b)) {
            mp[b] = b;
        }
        int tmp = mp[a];
        mp[a] = mp[b];
        mp[b] = tmp;
    }

    sort(bend(arrx));
    arrx.resize(unique(bend(arrx)) - arrx.begin());

    LL ans = 0;

    for (map <int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        int where = it -> ff;
        int what = it -> ss;
        //cout << where << " " << what << endl;
        ans += segtree_sum(1, 0, bdv - 1, lower_bound(bend(arrx), what) - arrx.begin() + 1, bdv - 1);
        if (what > where) {
            ans += what - where - (upper_bound(bend(arrx), what) - upper_bound(bend(arrx), where));
        } else {
            ans += where - what - (upper_bound(bend(arrx), where) - upper_bound(bend(arrx), what));
        }
        //cout << ans << endl;
        segtree_plus(lower_bound(bend(arrx), what) - arrx.begin());
    }

    cout << ans << endl;

    return 0;
}