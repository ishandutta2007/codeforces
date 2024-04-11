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

int n, k;
vector <pii> points;
set <pii> lr, ud;

inline int rm(int pos) {
    lr.erase({points[pos].ff, pos});
    ud.erase({points[pos].ss, pos});
    return 0;
}

inline int add(int pos) {
    lr.insert({points[pos].ff, pos});
    ud.insert({points[pos].ss, pos});
    return 0;
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        points.puba({x1 + x2, y1 + y2});
        lr.insert({x1 + x2, i});
        ud.insert({y1 + y2, i});
    }

    ll ans = 9e18;
    
    vector <int> removed1;        
    for (int i1 = 0; i1 <= k; ++i1) {
        if (i1) {
            int pos = lr.rbegin() -> ss;
            removed1.puba(pos);
            rm(pos);
        }
        vector <int> removed2;
        for (int i2 = 0; i1 + i2 <= k; ++i2) {                            
            if (i2) {
                int pos = lr.begin() -> ss;
                removed2.puba(pos);
                rm(pos);
            }
            vector <int> removed3;
            for (int i3 = 0; i1 + i2 + i3 <= k; ++i3) {
                if (i3) {
                    int pos = ud.begin() -> ss;
                    removed3.puba(pos);
                    rm(pos);
                }
                vector <int> removed4;        
                for (int i4 = 0; i1 + i2 + i3 + i4 <= k; ++i4) {                                    
                    if (i4) {
                        int pos = ud.rbegin() -> ss;
                        removed4.puba(pos);
                        rm(pos);
                    }
                    ans = min(ans, (ll) (max((lr.rbegin() -> ff - lr.begin() -> ff + 1) / 2, 1)) * (max((ud.rbegin() -> ff - ud.begin() -> ff + 1) / 2, 1)));
                }
                for (int el: removed4) {
                    add(el);
                }
            }
            for (int el: removed3) {
                add(el);
            }
        }
        for (int el: removed2) {
            add(el);
        }        
    }

    cout << ans << "\n";

    return 0;
}