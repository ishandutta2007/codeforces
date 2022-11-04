#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

ll aint[4 * MAXN + 1][1 << 5];
int k;

inline void refresh(int nod) {
    for(int conf = 0; conf < (1 << k); conf++) {
        aint[nod][conf] = max(aint[2 * nod][conf], aint[2 * nod + 1][conf]);
    }
}

void update(int nod, int left, int right, int pos, vector <int> &a) {
    if(left == right) {
        for(int conf = 0; conf < (1 << k); conf++) {
            aint[nod][conf] = 0;
            for(int i = 0; i < k; i++) {
                if(conf & (1 << i))
                    aint[nod][conf] += a[i];
                else
                    aint[nod][conf] -= a[i];
            }
        }
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos, a);
        else
            update(2 * nod + 1, mid + 1, right, pos, a);
        refresh(nod);
    }
}

ll aux[1 << 5];

void query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        for(int conf = 0; conf < (1 << k); conf++) {
            aux[conf] = max(aux[conf], aint[nod][conf]);
        }
    }
    else {
        int mid = (left + right) / 2;
        if(l <= mid)
            query(2 * nod, left, mid, l, r);
        if(mid < r)
            query(2 * nod + 1, mid + 1, right, l, r);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        vector <int> a(k);
        for(j = 0; j < k; j++) {
            cin >> a[j];
        }
        update(1, 1, n, i, a);
    }
    cin >> q;
    while(q > 0) {
        q--;
        int type;
        cin >> type;
        if(type == 1) {
            int pos;
            cin >> pos;
            vector <int> a(k);
            for(i = 0; i < k; i++) {
                cin >> a[i];
            }
            update(1, 1, n, pos, a);
        }
        else {
            int l, r;
            cin >> l >> r;
            for(int conf = 0; conf < (1 << k); conf++) {
                aux[conf] = -1e18;
            }
            query(1, 1, n, l, r);
            ll ans = 0;
            for(int conf = 0; conf < (1 << k); conf++) {
                ans = max(ans, aux[conf] + aux[conf ^ ((1 << k) - 1)]);
            }
            cout << ans << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}