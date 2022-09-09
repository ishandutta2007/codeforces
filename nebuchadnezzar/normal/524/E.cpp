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
const int bd = 17, bdv = 1 << bd, MAXN = 1e5 + 5, INF = 1e9 + 9;

const int inp_size = 65536;

char inpa[inp_size];
int inpl = 0;
int inpc = 0;

void scanint(int &x) {    
    bool flag = false;
    int nown = 0;
    while (true) {
        for (; inpc < inpl; ++inpc) {
            if (inpa[inpc] < '0' || inpa[inpc] > '9') {
                if (flag) {                    
                    x = nown;
                    return;
                } 
            } else {
                flag = true;
                nown = nown * 10 + inpa[inpc] - '0';
            }
        }
        inpc = 0;
        if (!(inpl = fread(inpa, 1, inp_size, stdin))) {
            x = nown;
            return;
        }
    }
    assert(false);
    return;    
}

int n, m, q, k;

vector <pii > hor, ver;
int rmq[bdv * 2];
vector <pair <pii, pii > > inp;

int segtree_set(int pos, int num) {
    pos += bdv;
    rmq[pos] = num;
    pos /= 2;
    while (pos) {
        rmq[pos] = min(rmq[pos * 2], rmq[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

int segtree_get(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return INF;
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return min(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm + 1, vr, l, r));
}

bool ans[MAXN * 2];

int main() {    
    //ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> m >> k >> q;
    //scanf("%d%d%d%d", &n, &m, &k, &q);
    scanint(n);
    scanint(m);
    scanint(k);
    scanint(q);

    for (int i = 0; i < k; ++i) {
        int x, y;
        //cin >> x >> y;
        //scanf("%d%d", &x, &y);
        scanint(x);
        scanint(y);
        --x;--y;
        hor.puba(mapa(x, -y));
        ver.puba(mapa(y, -x));
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        //cin >> x1 >> y1 >> x2 >> y2;
        //scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanint(x1);
        scanint(y1);
        scanint(x2);
        scanint(y2);
        --x1;--y1;--x2;--y2;
        inp.puba(mapa(mapa(x1, y1), mapa(x2, y2)));
        hor.puba(mapa(x2, i + 1));
        ver.puba(mapa(y2, i + 1));
    }

    sort(bend(hor));
    sort(bend(ver));

    memset(rmq, -1, sizeof rmq);
    for (int i = 0; i < szof(hor); ++i) {
        if (hor[i].ss <= 0) {
            segtree_set(-hor[i].ss, hor[i].ff);
            //cout << -hor[i].ss << " " << hor[i].ff << endl;
        } else {
            int tmp = hor[i].ss - 1;
            int minn = segtree_get(1, 0, bdv - 1, inp[tmp].ff.ss, inp[tmp].ss.ss);
            if (minn >= inp[tmp].ff.ff) {
                ans[tmp] = true;
            }
        }
    }

    memset(rmq, -1, sizeof rmq);
    for (int i = 0; i < szof(ver); ++i) {
        if (ver[i].ss <= 0) {
            segtree_set(-ver[i].ss, ver[i].ff);
        } else {
            int tmp = ver[i].ss - 1;
            int minn = segtree_get(1, 0, bdv - 1, inp[tmp].ff.ff, inp[tmp].ss.ff);
            if (minn >= inp[tmp].ff.ss) {
                ans[tmp] = true;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}