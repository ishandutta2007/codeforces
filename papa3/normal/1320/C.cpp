#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

const int baza = 1 << 20;
int drz[2 * baza];
int to_push[2 * baza];

void add(int co, int pyt_pocz, int pyt_kon, int pocz = 0, int kon = baza, int gdzie = 1) {
    if (pyt_pocz <= pocz && kon <= pyt_kon) {
        drz[gdzie] += co;
        to_push[gdzie] += co;
        return;
    }
    
    if (pyt_kon <= pocz || kon <= pyt_pocz) {
        return;
    }
    
    int sr = (pocz + kon) / 2;
    add(co, pyt_pocz, pyt_kon, pocz, sr, gdzie * 2);
    add(co, pyt_pocz, pyt_kon, sr, kon, gdzie * 2 + 1);
    drz[gdzie] = max(drz[gdzie * 2], drz[gdzie * 2 + 1]) + to_push[gdzie];
}

struct Point {
    int x, y, z;
    
    bool operator<(const Point &other) const {
        if (y == other.y) {
            return x < other.x;
        }
        return y < other.y;
    }
};

vector<Point> v;

vector<pair<int, int> > X, Y;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    for (int a, b, i = 1; i <= n; i++) {
        cin >> a >> b;
        Y.push_back({a, b});
    }
    sort(Y.begin(), Y.end());
    
    for (int i = baza; i < 2 * baza; i++) {
        drz[i] = -INF;
    }
    for (int a, b, i = 1; i <= m; i++) {
        cin >> a >> b;
        drz[baza + a] = max(drz[baza + a], -b);
    }
    for (int i = 2 * baza - 2; i >= baza; i--) {
        drz[i] = max(drz[i], drz[i + 1]);
    }
    for (int i = baza - 1; i > 0; i--) {
        drz[i] = max(drz[i * 2], drz[i * 2 + 1]);
    }
    
    for (int x, y, z, i = 1; i <= p; i++) {
        cin >> y >> x >> z;
        v.push_back({x, y, z});
    }
    sort(v.begin(), v.end());
    int res = -INF;
    int it = 0;
    for (auto i : Y) {
        while (it < (int)v.size() && v[it].y < i.first) {
            add(v[it].z, v[it].x + 1, baza);
            it++;
        }
        res = max(res, drz[1] - i.second);
    }
    cout << res;
    
    
    return 0;
}/*

*/