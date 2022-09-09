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
typedef pair<ll, ll> pll;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

map<pll, ll> mem;

ll calc(ll len, ll flen) {
    if (mem.count({len, flen})) {
        return mem[{len, flen}];
    }
    auto& val = mem[{len, flen}];
    map<ll, ll> have;
    have[len] = 1;
    while (true) {
        auto p = *(--have.end());
        if (p.ff <= flen) {
            return val = have[flen];
        }
        have[(p.ff) / 2] += p.ss;
        have[(p.ff - 1) / 2] += p.ss;
        have.erase(p.ff);
    }
    return val = 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    
    ll n, k;
    scanf("%lld%lld", &n, &k);

    if (k == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (k == 2) {
        cout << n << "\n";
        return 0;
    }

    map<ll, ll> have;
    have[n - 2] = 1;

    k -= 2;
    ll rest = k;

    ll flen = 0;
    ll last_act = INFL;
    ll add = 0;
    while (true) {
        auto p = *(--have.end());
        if (!p.ss) {
            have.erase(p.ff);
            continue;
        }
        //cerr << p.ff << " " << p.ss << endl;
        if (rest <= p.ss) {
            flen = p.ff;
            break;
        }
        rest -= p.ss;
        add = p.ss;
        last_act = p.ff;
        have[(p.ff) / 2] += p.ss;
        have[(p.ff - 1) / 2] += p.ss;
        have.erase(p.ff);
    }

    bool flag = true;
    if (flen % 2 == 1) {
        if (last_act == flen + 1) {
            rest += add;
        }
        ++flen;
    }
    //ll shift = (flen - 1) / 2;

    ll l = 2, r = n - 1;
    //cerr << l << " " << r << " " << flen << " " << rest << endl;
    while (l + flen - 1 < r) {
        ll mid = l + (r - l) / 2;
        //cerr << l << " " << r << " " << mid << " " << rest << endl;
        ll val = calc(mid - l, flen) + (flag ? calc(mid - l, flen - 1) : 0);
        //cerr << val << endl;
        if (val >= rest) {
            r = mid - 1;
        } else {
            rest -= val;
            l = mid + 1;
        }
    }

    if (rest == 2) {
        cout << l + (r - l) / 2 + 1 << "\n";
    } else {
        cout << l + (r - l) / 2 << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}