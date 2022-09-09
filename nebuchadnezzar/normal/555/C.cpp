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
const int bd = 18, bdv = 1 << bd;

int n, q;
vector <pii > req;
vector <int> arrx;

int rmq1[bdv * 2];
int there1[bdv * 2];

int st1_segset(int v, int vl, int vr, int l, int r, int num);

int st1_pushdown(int v, int vl, int vr) {
    if (there1[v] == 0) {
        return 0;
    }
    int vm = (vl + vr) / 2;
    st1_segset(v * 2, vl, vm, vl, vm, there1[v]);
    st1_segset(v * 2 + 1, vm + 1, vr, vm + 1, vr, there1[v]);
    there1[v] = 0;
    return 0;
}

int st1_segset(int v, int vl, int vr, int l, int r, int num) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rmq1[v] = max(rmq1[v], num);
        there1[v] = max(there1[v], num);
        return 0;
    }
    int vm = (vl + vr) / 2;
    st1_pushdown(v, vl, vr);
    st1_segset(v * 2, vl, vm, l, r, num);
    st1_segset(v * 2 + 1, vm + 1, vr, l, r, num);
    rmq1[v] = max(rmq1[v * 2], rmq1[v * 2 + 1]);
    return 0;
}

int st1_get(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rmq1[v];
    }
    int vm = (vl + vr) / 2;
    st1_pushdown(v, vl, vr);    
    return max(st1_get(v * 2, vl, vm, l, r), st1_get(v * 2 + 1, vm + 1, vr, l, r));
}

int rmq2[bdv * 2];
int there2[bdv * 2];

int st2_segset(int v, int vl, int vr, int l, int r, int num);

int st2_pushdown(int v, int vl, int vr) {
    if (there2[v] == n + 1) {
        return 0;
    }
    int vm = (vl + vr) / 2;
    st2_segset(v * 2, vl, vm, vl, vm, there2[v]);
    st2_segset(v * 2 + 1, vm + 1, vr, vm + 1, vr, there2[v]);
    there2[v] = n + 1;
    return 0;
}

int st2_segset(int v, int vl, int vr, int l, int r, int num) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        //cerr << "v: " << v << endl;
        rmq2[v] = min(rmq2[v], num);
        there2[v] = min(there2[v], num);
        return 0;
    }
    int vm = (vl + vr) / 2;
    st2_pushdown(v, vl, vr);
    st2_segset(v * 2, vl, vm, l, r, num);
    st2_segset(v * 2 + 1, vm + 1, vr, l, r, num);
    rmq2[v] = min(rmq2[v * 2], rmq2[v * 2 + 1]);
    return 0;
}

int st2_get(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return n + 1;
    }
    if (l <= vl && vr <= r) {
        //cerr << "ans " << rmq2[v] << " " << v << endl;
        return rmq2[v];
    }
    int vm = (vl + vr) / 2;
    st2_pushdown(v, vl, vr);    
    return min(st2_get(v * 2, vl, vm, l, r), st2_get(v * 2 + 1, vm + 1, vr, l, r));
}

set <int> used;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d%d", &n, &q);

    for (int i = 0; i < q; ++i) {
        int x, y;
        char t;
        scanf("%d%d %c", &x, &y, &t);
        //cerr << t << endl;
        if (t == 'U') {
            req.puba(mapa(x, 0));
        } else {
            req.puba(mapa(x, 1));
        }
        arrx.puba(x);
    }

    arrx.puba(0);
    arrx.puba(n + 1);

    sort(bend(arrx));
    arrx.resize(unique(bend(arrx)) - arrx.begin());

    for (int i = 0; i < bdv; ++i) {
        rmq1[i + bdv] = 0;
        rmq2[i + bdv] = n + 1;
        there2[i + bdv] = n + 1;
        there2[i] = n + 1;
    }

    for (int i = bdv - 1; i > 0; --i) {
        rmq1[i] = max(rmq1[i * 2], rmq1[i * 2 + 1]);
        rmq2[i] = min(rmq2[i * 2], rmq2[i * 2 + 1]);
    }

    for (int i = 0; i < q; ++i) {
        if (!used.insert(req[i].ff).ss) {
            printf("0\n");
            continue;
        }
        //cerr << i << endl;
        int pos = lower_bound(bend(arrx), req[i].ff) - arrx.begin();
        if (req[i].ss == 0) {
            int tmp = st2_get(1, 0, bdv - 1, pos, pos);
            //cerr << "tmp " << tmp << " " << pos << endl;
            printf("%d\n", tmp - req[i].ff);
            int pos2 = lower_bound(bend(arrx), tmp) - arrx.begin();
            //cerr << arrx[pos] << " " << arrx[pos2 - 1] << " " << req[i].ff << endl;
            st1_segset(1, 0, bdv - 1, pos, pos2 - 1, req[i].ff);
        } else {
            //cerr << pos << endl;
            int tmp = st1_get(1, 0, bdv - 1, pos, pos);
            //cerr << "tmp " << tmp << endl;
            printf("%d\n", req[i].ff - tmp);
            int pos2 = lower_bound(bend(arrx), tmp) - arrx.begin();
            //cerr << pos2 + 1 << " " << pos << " " << req[i].ff << endl;
            st2_segset(1, 0, bdv - 1, pos2 + 1, pos, req[i].ff);
        }
    }

    return 0;
}