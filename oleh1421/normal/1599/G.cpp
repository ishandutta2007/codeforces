//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define double long double
#define ft first
#define sc second
#define pb push_back
#define booost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define all(x) (x).begin(),(x).end()
#define file(x) freopen(string(string((x)) + ".in").c_str(), "r", stdin); freopen(string(string((x)) + ".out").c_str(), "w", stdout);
#define GG cout << " OPA " << '\n';

using namespace std;
using namespace __gnu_pbds;
typedef pair <int, int> pi;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution <int> uid(0, 1000000000);
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5;
const int K = 21;
const int KS = 1e6 + 5;
const int P = 37;
const int INF = 1e9;
const double d_INF = 2000000000.0;
const double EPS = 1e-20;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
const int LOG = 17;
const double PI = 3.14159265359;

pi a[N];

double dist(int x, int y) {
    int cur = (a[x].ft - a[y].ft) * (a[x].ft - a[y].ft) + (a[x].sc - a[y].sc) * (a[x].sc - a[y].sc);
    return sqrtl((double)cur);
}

bool line(int x, int y, int z) {
    int x1 = a[x].ft; int x2 = a[y].ft; int x3 = a[z].ft;
    int y1 = a[x].sc; int y2 = a[y].sc; int y3 = a[z].sc;
    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) == 0) return true;
    else return false;
}

bool cmp(int x, int y) {
    return a[x] < a[y];
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    if (n == 3) {
        vector <int> vec;
        for (int i = 1; i <= n; i ++) {
            if (i != k) vec.pb(i);
        }
        cout << fixed << setprecision(10) << min({dist(k, vec[0]) + dist(vec[0], vec[1]), dist(k, vec[1]) + dist(vec[0], vec[1])});
        return;
    }
    pair <int, pair <int, int> > ln = {0, {0, 0}};
    for (int i = 1; i <= 2; i ++) {
        for (int j = i + 1; j <= 3; j ++) {
            for (int z = j + 1; z <= 4; z ++) {
                if (line(i, j, z)) ln = {i, {j, z}};
            }
        }
    }
    assert(ln.ft);
    int bad = 0;
    for (int i = 1; i <= n; i ++) {
        if (!line(i, ln.ft, ln.sc.ft)) {
            bad = i;
            break;
        }
    }
    assert(bad);
    vector <int> vec;
    for (int i = 1; i <= n; i ++) {
        if (i == bad) continue;
        vec.pb(i);
    }
    sort(all(vec), cmp);
    if (bad == k) {
        cout << fixed << setprecision(10) << min({dist(k, vec[0]) + dist(vec[0], vec.back()), dist(k, vec.back()) + dist(vec[0], vec.back())});
        return;
    }
    int id;
    for (int i = 0; i < vec.size(); i ++) {
        if (vec[i] == k) {
            id = i;
            break;
        }
    }
    double ans = d_INF;
    for (int i = vec.size() - 1; i >= 0; i --) {
        ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec[0]) + dist(vec[0], vec.back()));
        ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec.back()) + dist(vec[0], vec.back()));
        if (i <= id) ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec[0]) + (i - 1 >= 0 ? dist(vec[0], vec[i - 1]) : 0) + 2 * dist(vec[id], vec.back()));
        if (i <= id) ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + (i - 1 >= 0 ? dist(bad, vec[i - 1]) : 0) + (i - 1 >= 0 ? dist(vec[0], vec[i - 1]) : 0) + 2 * dist(vec[id], vec.back()));
        if (i >= id) ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec.back()) + (i + 1 < vec.size() ? dist(vec.back(), vec[i + 1]) : 0) + 2 * dist(vec[id], vec[0]));
        if (i >= id) ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + (i + 1 < vec.size() ? dist(bad, vec[i + 1]) : 0) + (i + 1 < vec.size() ? dist(vec.back(), vec[i + 1]) : 0) + 2 * dist(vec[id], vec[0]));
        if (i == vec.size() - 1) {
            ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + (id - 1 >= 0 ? dist(bad, vec[id - 1]) : 0) + (id - 1 >= 0 ? dist(vec[0], vec[id - 1]) : 0));
            ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec[0]) + (id - 1 >= 0 ? dist(vec[0], vec[id - 1]) : 0));
        }
        if (i == 0) {
            ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + (id + 1 < vec.size() ? dist(bad, vec[id + 1]) : 0) + (id + 1 < vec.size() ? dist(vec[id + 1], vec.back()) : 0));
            ans = min(ans, dist(vec[i], vec[id]) + dist(vec[i], bad) + dist(bad, vec.back()) + (id + 1 < vec.size() ? dist(vec.back(), vec[id + 1]) : 0));
        }
    }
    cout << fixed << setprecision(10) << ans;
}

main () {
    int test = 1;
    booost;
//    cin >> test;
    while (test --) {
        solve();
    }
}