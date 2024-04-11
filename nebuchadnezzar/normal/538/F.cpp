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
const int MAXN = 2e5 + 5;//, bd = 18, bdv = 1 << bd;

int n;
int arr[MAXN];

/*
int rsq[bdv * 2];

int segtree_segplus(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rsq[v] += 1;
        return 0;
    }
    int vm = (vl + vr) / 2;
    segtree_segplus(v * 2, vl, vm, l, r);
    segtree_segplus(v * 2 + 1, vm + 1, vr, l, r);
    return 0;
}

int segtree_get(int pos) {
    pos += bdv;
    int ret = 0;
    while (pos) {
        ret += rsq[pos];
        pos /= 2;
    }
    return ret;
}*/

//vector <pii > pm;
int pm[2][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //cin >> n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        //cin >> arr[i];
        scanf("%d", &arr[i]);
    }

    LL ans = 0;
    int rg = min((int) sqrt(n), n - 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= rg; ++j) {
            if (arr[i] < arr[(i - 1) / j]) {
                //segtree_segplus(1, 0, bdv - 1, j, j);
                pm[0][j] += 1;
                pm[1][j] += 1;
            }
        }
    }

    for (int i = 0; i * (rg + 1) + 1 < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] >= arr[i]) {
                continue;
            }
            int l = j / (i + 1);
            if (l * (i + 1) < j) {
                ++l;
            }
            int r = 0;
            if (i == 0) {
                r = n - 1;   
            } else {
                r = j / i;
                if (r * i >= j) {
                    --r;
                }
            }
            l = max(l, rg + 1);
            //ans += max(0, r - l + 1);
            //segtree_segplus(1, 0, bdv - 1, l, r);
            if (l <= r) {
                pm[0][l] += 1;
                pm[1][r] += 1;
            }
            //cout << l << " " << r << endl;
        }
    }

    //sort(bend(pm));
    int bal = 0;
    //int c = 0;
    

    for (int i = 1; i <= n - 1; ++i) {
        bal += pm[0][i];
        cout << bal << " ";
        bal -= pm[1][i];
    }
    cout << endl;

    return 0;
}