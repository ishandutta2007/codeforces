#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 505;

struct matrix {
    vector<bitset<MAXN>> m;

    matrix() {
        m.resize(MAXN);
    }
};

bitset<MAXN> temp[MAXN];
int n, m;

matrix product(const matrix& a, const matrix& b) {
    matrix ret;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = b.m[j][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((a.m[i] & temp[j]).any()) {
                ret.m[i][j] = 1;
            } else {
                ret.m[i][j] = 0;
            }
        }
    }
    return ret;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    matrix a, na;

    for (int i = 0; i < m; ++i) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        --u; --v;
        if (!t) {
            a.m[u][v] = 1;
        } else {
            na.m[u][v] = 1;
        }
    }

    vector<pair<matrix, matrix>> arr = {{a, na}};

    for (int i = 0; i < 60; ++i) {
        //cerr << i << endl;
        arr.puba({product(arr.back().ff, arr.back().ss), product(arr.back().ss, arr.back().ff)});
        //cerr << "@" << endl; 
    }

    bool flag = 0;
    ll tot = 0;

    matrix cur;
    for (int i = 0; i < n; ++i) {
        cur.m[i][i] = 1;
    }

    for (int i = szof(arr) - 1; i >= 0; --i) {
        auto tmp = product(cur, flag ? arr[i].ss : arr[i].ff);
        if (tmp.m[0].any()) {
            tot += 1ll << i;
            cur = tmp;
            flag ^= 1;
        }
    }

    const ll MAXANS = 1e18;
    //cerr << MAXANS << endl;

    if (tot > MAXANS) {
        cout << "-1\n";
    } else {
        cout << tot << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}