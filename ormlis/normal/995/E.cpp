#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int p;

int pw(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = (1ll * a * a) % p) if (b & 1) r = (1ll * r * a) % p;
    return r;
}

vector<int> check(int a, int b) {
    map<int, int> pa, pb;
    pa[a] = -1;
    pb[b] = -1;
    queue<int> qa, qb;
    qa.push(a);
    qb.push(b);
    int f = -1;
    while (true) {
        {
            int v = qa.front();
            qa.pop();
            int v1 = (v + 1) % p;
            if (!pa.count(v1)) {
                pa[v1] = v;
                qa.push(v1);
                if (pb.count(v1)) {
                    f = v1;
                    break;
                }
            }
            int v2 = (v - 1) % p;
            if (!pa.count(v2)) {
                pa[v2] = v;
                qa.push(v2);
                if (pb.count(v2)) {
                    f = v2;
                    break;
                }
            }
            int v3 = pw(v, p - 2);
            if (!pa.count(v3)) {
                pa[v3] = v;
                qa.push(v3);
                if (pb.count(v3)) {
                    f = v3;
                    break;
                }
            }
        }

        {
            int v = qb.front();
            qb.pop();
            int v1 = (v + 1) % p;
            if (!pb.count(v1)) {
                pb[v1] = v;
                qb.push(v1);
                if (pa.count(v1)) {
                    f = v1;
                    break;
                }
            }
            int v2 = (v - 1 + p) % p;
            if (!pb.count(v2)) {
                pb[v2] = v;
                qb.push(v2);
                if (pa.count(v2)) {
                    f = v2;
                    break;
                }
            }
            int v3 = pw(v, p - 2);
            if (!pb.count(v3)) {
                pb[v3] = v;
                qb.push(v3);
                if (pa.count(v3)) {
                    f = v3;
                    break;
                }
            }
        }
    }
    vector<int> res;
    int t = f;
    while(t != a) {
        int to = pa[t];
        if ((to + 1) % p == t) {
            res.push_back(1);
        } else if ((to - 1 + p) % p == t) {
            res.push_back(2);
        } else {
            res.push_back(3);
        }
        t = to;
    }
    reverse(all(res));
    t = f;
    while(t != b) {
        int to = pb[t];
        if ((t + 1) % p == to) {
            res.push_back(1);
        } else if ((t - 1 + p) % p == to) {
            res.push_back(2);
        } else {
            res.push_back(3);
        }
        t = to;
    }
    return res;
}

void solve() {
    int u, v; cin >> u >> v >> p;
    auto res = check(u, v);
    cout << res.size() << '\n';
    for(auto &s : res) {
        cout << s << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}