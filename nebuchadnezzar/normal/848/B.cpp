#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);

    vector<tuple<int, int, int>> vars;
    map<int, vector<tuple<int, int, int>>> classes;
    map<int, queue<pii>> to;
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        scanf("%d%d%d", &g, &p, &t);
        if (g == 1) {
            classes[p - t].puba({p, t, i});
            //cerr << p - t << endl;
            //to[p - t].puba({p, h});
        } else {
            vars.puba({p, t, i});
        }
    }
    
    sort(bend(vars));
    reverse(bend(vars));
    vector<pii> ans(n);

    for (auto& v : classes) {
        sort(bend(v.ss));
        auto& q = to[v.ff];
        for (auto t : v.ss) {
            q.push({get<0>(t), h});
        }
    }

    for (auto p : vars) {
        int y, t, ind;
        tie(y, t, ind) = p;

        int tmp = -(t - y);
        //cerr << tmp << endl;
        if (to.count(tmp)) {
            auto& q = to[tmp];
            ans[ind] = q.front();
            q.pop();
            q.push({w, y});
        } else {
            ans[ind] = {w, y};
        }
    }

    for (auto& v : classes) {
        auto& q = to[v.ff];
        for (auto t : v.ss) {
            ans[get<2>(t)] = q.front();
            q.pop();
        }
    }
    

    for (auto p : ans) {
        cout << p.ff << " " << p.ss << "\n";
    }
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}