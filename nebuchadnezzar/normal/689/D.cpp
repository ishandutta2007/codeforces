#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];
int b[MAXN];
vector<int> arra[MAXN], arrb[MAXN];
vector<int> vala, valb;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        vala.puba(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        valb.puba(b[i]);
    }

    sort(bend(vala));
    vala.resize(unique(bend(vala)) - vala.begin());

    sort(bend(valb));
    valb.resize(unique(bend(valb)) - valb.begin());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(bend(vala), a[i]) - vala.begin();
        arra[a[i]].puba(i);
    }
    
    for (int i = 0; i < n; ++i) {
        b[i] = lower_bound(bend(valb), b[i]) - valb.begin();
        arrb[b[i]].puba(i);
    }

    set<int> now;
    vector<pii> nearestb(n);
    now.insert(n);
    now.insert(-1);
    for (int i = 0; i < szof(valb); ++i) {
        for (int p: arrb[i]) {
            nearestb[p].ss = *now.lower_bound(p);
            auto tmp = now.lower_bound(p);
            --tmp;
            nearestb[p].ff = *tmp;
        }

        for (int p: arrb[i]) {
            now.insert(p);
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cerr << nearestb[i] << " ";
    }
    cerr << endl;*/
    now.clear();
    now.insert(n);
    now.insert(-1);

    ll ans = 0;
    for (int i = szof(vala) - 1; ~i; --i) {
        int prevp = -1;
        for (int p: arra[i]) {
            auto tmp = now.lower_bound(p);
            --tmp;
            int lg = max(*tmp, prevp);
            int rg = *now.lower_bound(p);
            int indvb = lower_bound(bend(valb), vala[i]) - valb.begin();
            if (indvb < szof(valb) && valb[indvb] == vala[i]) {
                //cerr << "@ " << p << endl;
                //cerr << *tmp << " " << prevp << " " << rg << endl;
                auto q = lower_bound(bend(arrb[indvb]), p);
                int posb1 = n;
                if (q != arrb[indvb].end()) {
                    posb1 = *q;
                }
                int posb2 = -1;
                if (q != arrb[indvb].begin()) {
                    --q;
                    posb2 = *q;
                }
                if (posb1 != n) {
                    int posb = posb1;
                    //cerr << posb << " " << nearestb[posb] << endl;
                    int tmp_rg = min(rg, nearestb[posb].ss);
                    int tmp_lg = max(max(lg, nearestb[posb].ff), posb2);
                    if (tmp_rg > posb && tmp_lg < p) {
                        ans += (ll) (tmp_rg - posb) * (p - tmp_lg);
                    }
                }
                if (posb2 != -1) {
                    int posb = posb2;
                    //cerr << posb << " " << nearestb[posb] << endl;
                    int tmp_rg = min(rg, nearestb[posb].ss);
                    int tmp_lg = max(lg, nearestb[posb].ff);
                    if (tmp_lg < posb && tmp_rg > p) {
                        ans += (ll) (tmp_rg - p) * (posb - tmp_lg);
                    }
                }
            }
            prevp = p;
        }

        for (int p: arra[i]) {
            now.insert(p);
        }
    }

    cout << ans << "\n";
    return 0;
}