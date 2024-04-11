#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long LL;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 5e5 + 5, SQRTN = 700;

int n, q;
LL arr[MAXN];
vector <LL> sorted[MAXN];
LL addit[MAXN];
vector <LL> split;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int c = 0;
    for (int i = 0; i < n; i += SQRTN) {
        split.puba(i);
        for (int j = 0; j < SQRTN && i + j < n; ++j) {
            sorted[c].puba(arr[i + j]);
        }
        sort(bend(sorted[c]));
        ++c;
    }
    split.puba(n);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            LL x;
            cin >> l >> r >> x;
            --l;--r;
            int lp = upper_bound(bend(split), l) - split.begin() - 1;
            sorted[lp].clear();
            for (int j = split[lp]; j < split[lp + 1]; ++j) {
                arr[j] += addit[lp];
                if (j >= l && j <= r) {
                    arr[j] += x;
                }
                sorted[lp].puba(arr[j]);
            }
            addit[lp] = 0;
            sort(bend(sorted[lp]));
            
            int rp = upper_bound(bend(split), r) - split.begin() - 1;
            if (rp > lp) {
                sorted[rp].clear();
                for (int j = split[rp]; j < split[rp + 1]; ++j) {
                    arr[j] += addit[rp];
                    if (l <= j && j <= r) {
                        arr[j] += x;
                    }
                    sorted[rp].puba(arr[j]);
                }
                addit[rp] = 0;
                sort(bend(sorted[rp]));
            }

            for (int j = lp + 1; j < rp; ++j) {
                addit[j] += x;
            }
        } else {
            LL y;
            cin >> y;
            int lg = szof(split), rg = -1;
            for (int j = 0; j < szof(split) - 1; ++j) {
                if (*lower_bound(bend(sorted[j]), y - addit[j]) == y - addit[j]) {
                    lg = min(lg, j);
                    rg = max(rg, j);
                }
            }
            if (lg > rg) {
                cout << -1 << endl;
                continue;
            }
            int l = n, r = -1;
            for (int j = split[lg]; j < split[lg + 1]; ++j) {
                if (arr[j] == y - addit[lg]) {
                    l = j;
                    break;
                }
            }
            for (int j = split[rg + 1] - 1; j >= split[rg]; --j) {
                if (arr[j] == y - addit[rg]) {
                    r = j;
                    break;
                }
            }
            cout << r - l << endl;
        }
        /*
        for (int j = 0; j < n; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;*/
    }

    return 0;
}