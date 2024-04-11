#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
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

vector <pii > inp;
int rmq[bdv * 2];

int segtree_set(int pos, int num) {
    pos += bdv;
    rmq[pos] = num;
    pos /= 2;
    while (pos > 0) {
        rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

int segtree_get(int v, int vl, int vr, int l, int r) {
    if (r < vl || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return max(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm + 1, vr, l, r));
}

vector <int> arrx;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, w;
        cin >> x >> w;
        arrx.puba(x + w);
        //cout << x + w << endl;

        inp.puba(mapa(x, w));
    }

    sort(bend(inp));
    sort(bend(arrx));
    arrx.resize(unique(bend(arrx)) - arrx.begin());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = upper_bound(bend(arrx), inp[i].ff - inp[i].ss) - arrx.begin() - 1;
        //cout << inp[i].ff << " " << inp[i].ss << " " << tmp << endl;
        int nans = segtree_get(1, 0, bdv - 1, 0, tmp);
        //cout << nans << endl;
        ans = max(ans, nans + 1);
        tmp = lower_bound(bend(arrx), inp[i].ff + inp[i].ss) - arrx.begin();
        segtree_set(tmp, nans + 1);
        
        //cout << "set " << tmp << " " << nans + 1 << endl;
    }

    cout << ans << endl;

    return 0;
}