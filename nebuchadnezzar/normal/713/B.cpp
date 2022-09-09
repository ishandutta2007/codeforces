#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int n;
map<vector<int>, int> mem;

int inside(vector<int> a, vector<int> b) {
    return b[0] <= a[0] && a[2] <= b[2] && b[1] <= a[1] && a[3] <= b[3];
}

vector<int> ra = {30000, 30000, 30000, 30000}, rb = {30001, 30000, 30001, 30000};

int counter = 0;
int _ask(vector<int> v) {
    ++counter;
    assert(counter <= 200);
    return inside(ra, v) + inside(rb, v);
}

int ask(int x1, int y1, int x2, int y2) {
    if (mem.count({x1, y1, x2, y2})) {
        return mem[{x1, y1, x2, y2}];
    }
    
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int ret;
    scanf("%d", &ret);
    //int ret = _ask({x1, y1, x2, y2});
    return mem[{x1, y1, x2, y2}] = ret;
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    vector<int> gx, gy;

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, 1, n, mid) == 2) {
            r = mid;
        } else {
            l = mid;
        }
    }
    gy.puba(r);

    l = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, 1, n, mid) >= 1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    gy.puba(r);

    l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, mid, n, n) == 2) {
            l = mid;
        } else {
            r = mid;
        }
    }

    gy.puba(l);

    r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, mid, n, n) >= 1) {
            l = mid;
        } else {
            r = mid;
        }
    }

    gy.puba(l);




    l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, 1, mid, n) == 2) {
            r = mid;
        } else {
            l = mid;
        }
    }
    gx.puba(r);

    l = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(1, 1, mid, n) >= 1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    gx.puba(r);

    l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(mid, 1, n, n) == 2) {
            l = mid;
        } else {
            r = mid;
        }
    }

    gx.puba(l);

    r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ask(mid, 1, n, n) >= 1) {
            l = mid;
        } else {
            r = mid;
        }
    }

    gx.puba(l);

    sort(bend(gx));
    sort(bend(gy));

    vector<vector<int>> ans;

    for (int x1 = 0; x1 < szof(gx); ++x1) {
        for (int x2 = x1 + 1; x2 < szof(gx); ++x2) {
            for (int y1 = 0; y1 < szof(gy); ++y1) {
                for (int y2 = y1 + 1; y2 < szof(gy); ++y2) {
                    if (ask(gx[x1], gy[y1], gx[x2], gy[y2]) == 1) {
                        ans.puba({gx[x1], gy[y1], gx[x2], gy[y2]});
                    }
                }
            }
        }
    }

    sort(bend(ans));
    ans.resize(unique(bend(ans)) - ans.begin());

    vector<vector<int>> good;

    for (int i = 0; i < szof(ans); ++i) {
        bool flag = true;
        for (int j = 0; j < szof(ans); ++j) {
            if (i != j && inside(ans[j], ans[i])) {
                flag = false;
            }
        }
        if (flag) {
            good.puba(ans[i]);
        }
    }

    assert(szof(good) == 2);
    cout << "! ";
    for (int i = 0; i < 2; ++i) {
        for (int num: good[i]) {
            cout << num << " ";
        }
    }
    cout << endl;

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}