#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 3e5 + 5, bd = 19, bdv = 1 << bd;
const int MAXK = 1e6 + 5;

int n;
ll k;
ll inp[MAXN];
ll ssum[MAXN];
vector <pii > req[MAXK];
vector <int> thiss[MAXK];
pii rmq[bdv * 2];

pii segtree_getmax(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return mapa(-1, -1);
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return max(segtree_getmax(v * 2, vl, vm, l, r), segtree_getmax(v * 2 + 1, vm + 1, vr, l, r));
}

int rec(int l, int r) {
    //cerr << l << " " << r << endl;
    if (l >= r) {
        return 0;
    }
    pii tmp = segtree_getmax(1, 0, bdv - 1, l, r);
    int pos = tmp.ss;
    if (pos - l < r - pos) {
        for (int i = l; i <= pos; ++i) {
            int val = (ssum[i] + inp[pos]) % k;
            if (i == pos) {
                req[val].puba(mapa(pos + 2, r + 1));
            } else {
                req[val].puba(mapa(pos + 1, r + 1));
            }
        }   
    } else {
        for (int i = pos; i <= r; ++i) {
            int val = (ssum[i + 1] - inp[pos]) % k;
            if (val < 0) {
                val += k;
            }
            if (i == pos) {
                req[val].puba(mapa(l, pos - 1));
            } else {
                req[val].puba(mapa(l, pos));
            }
        }
    }
    rec(l, pos - 1);
    rec(pos + 1, r);
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    thiss[0].puba(0);
    //cin >> n >> k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        //cin >> inp[i];
        scanf("%I64d", &inp[i]);
        ssum[i + 1] = (ssum[i] + inp[i]) % k;
        thiss[ssum[i + 1]].puba(i + 1);
        rmq[i + bdv] = mapa(inp[i], i);
    }
    
    for (int i = bdv - 1; i > 0; --i) {
        rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
    }

    rec(0, n - 1);

    ll ans = 0;

    for (int i = 0; i < k; ++i) {
        /*
        cerr << "i: " << i << endl;
        for (int j = 0; j < szof(thiss[i]); ++j) {
            cerr << thiss[i][j] << " ";
        }
        cerr << endl;
        */
        for (int j = 0; j < szof(req[i]); ++j) {
            //cerr << req[i][j].ff << " " << req[i][j].ss << endl;
            ans += upper_bound(bend(thiss[i]), req[i][j].ss) - lower_bound(bend(thiss[i]), req[i][j].ff);
        }
    }

    cout << ans << endl;
    return 0;
}