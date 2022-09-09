#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5, bd = 17, bdv = 1 << bd;
const int MAXK = 15;

ll rsq[MAXK][bdv * 2];
int n, k;

int segtree_set(int num, int pos, ll val) {
    pos += bdv;
    rsq[num][pos] = val;
    pos /= 2;
    while (pos) {
        rsq[num][pos] = rsq[num][pos * 2] + rsq[num][pos * 2 + 1];
        pos /= 2;
    }
    return 0;
}

ll segtree_get(int num, int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[num][v];
    }
    int vm = (vl + vr) / 2;
    return segtree_get(num, v * 2, vl, vm, l, r) + segtree_get(num, v * 2 + 1, vm + 1, vr, l, r);
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);
    
    segtree_set(0, 0, 1);

    int last = 0;
    for (int i = 0; i < n; ++i) {        
        int num;
        scanf("%d", &num);
        last = num;
        //cerr << rsq[0][bdv] << " ";
        for (int j = 0; j <= k; ++j) {
            segtree_set(j + 1, num, segtree_get(j, 1, 0, bdv - 1, 0, num - 1));
            //cerr << segtree_get(j, 1, 0, bdv - 1, 0, i) << " ";
        }
        /*
        for (int j = 0; j <= k + 1; ++j) {
            cerr << rsq[j][num + bdv] << " ";
        }
        cerr << endl;
        */
    }        

    cout << rsq[k + 1][1] << "\n";

    return 0;
}