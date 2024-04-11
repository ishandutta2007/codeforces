#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <unordered_map>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define prev prev_

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int bd = 20, bdv = 1 << bd, INF = 1e9 + 9;

int n, m;

unordered_map <int, int> prev;
int rmq[bdv * 2];

int segtree_get(int v, int vl, int vr, int l, int r) {
    if (r < vl || vr < l) {
        return INF;
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return min(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm + 1, vr, l, r));
}

int segtree_set(int pos, int num) {
    pos += bdv;
    rmq[pos] = min(rmq[pos], num);
    pos /= 2;
    while (pos > 0) {
        rmq[pos] = min(rmq[pos * 2], rmq[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> m;
    scanf("%d%d", &n, &m);

    memset(rmq, 127, sizeof rmq);

    vector <pair <int, pair <int, pii > > > v;
    for (int i = 0; i < n; ++i) {        
        int num;
        scanf("%d", &num);
        if (prev.count(num)) {            
            v.puba(mapa(i, mapa(0, mapa(i - prev[num], prev[num]))));
            //cout << l << " " << i - prev[num] + 1 << endl;
            //rmq[l] = min(rmq[l], i - prev[num]);
        }
        //cout << num << " @ " << i << endl;
        prev[num] = i;
    }

    //scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;--r;
        v.puba(mapa(r, mapa(1, mapa(l, i))));
    }

    sort(bend(v));
    int ans[m];

    for (int i = 0; i < szof(v); ++i) {
        if (v[i].ss.ff == 0) {
            segtree_set(v[i].ss.ss.ss, v[i].ss.ss.ff);
        } else {
            ans[v[i].ss.ss.ss] = segtree_get(1, 0, bdv - 1, v[i].ss.ss.ff, v[i].ff);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (ans[i] > n) {
            printf("-1\n");
        } else {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}