#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <ctime>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

#define TEST 0

ll mrand() {
    ll x = rand();
    x *= RAND_MAX;
    x ^= rand();
    return x;
}

double gett() {
    return clock() * 1.0 / CLOCKS_PER_SEC;
}

struct query {
    int type;
    ll x, k;

    void read() {
#if !TEST
        scanf("%d", &type);
        if  (type == 1 || type == 2) {
            scanf("%lld%lld", &x, &k);
        } else {
            assert(type == 3);
            scanf("%lld", &x);
        }
#else
        const ll M = 1e18;
        type = 1 + rand() % 3;
        type = 3;
        if  (type == 1 || type == 2) {
            x = mrand() % M + 1;
            k = mrand() % M + 1;
        } else {
            x = mrand() % M + 1;
        }
#endif
    }
};

vector<query> qs;

bool read() {
#if !TEST
    int q;
    if  (scanf("%d", &q) < 1) {
        return 0;
    }
#else
    int q = 1e5;
#endif

    qs.resize(q);
    forn(i, q) {
        qs[i].read();
    }
    return 1;
}

const int B = 62;

ll first_node[B];
ll first_val[B];

inline int level(ll x) {
    assert(x >= 1);
    int ans = 0;
    while (x > 1) {
        ++ans;
        x /= 2;
    }
    return ans;
}

inline ll left_val(int i) {
    return 1ll << i;
}

inline ll right_val(int i) {
    return left_val(i + 1) - 1;
}

inline ll size_level(int i) {
    return 1ll << i;
}

void norm(ll& v, int i) {
    const ll s = size_level(i);
    while (v < left_val(i)) {
        v += s;
    }
    while (v > right_val(i)) {
        v -= s;
    }
}

ll get_node(ll x, int i) {
    const ll s = size_level(i);
    ll offset = x - first_val[i];
    if  (offset < 0) {
        offset += s;
    } 

    ll v = first_node[i] + offset;
    norm(v, i);

    return v; 
}

ll get_val(ll v, int i) {
    ll val = first_val[i] + (v - first_node[i]);
    norm(val, i);
    return val;
}

void get_ans(ll v, int i, vll& ans) {
    while (1) {
        if  (v == 1) {
            ans.pb(1);
            return;
        }

        ans.pb(get_val(v, i));

        const ll s = size_level(i);
        ll pos = v - first_node[i];
        pos = (pos % s + s) % s; 
        ll real_v = left_val(i) + pos;

//        ll real_v = v;

        --i;
        v = real_v / 2;
    }
}

void solve() {
    {
        ll v = 1;
        forn(i, B) {
            first_node[i] = v;
            first_val[i] = v;
            v *= 2;
        }
    }

    for (const auto& q : qs) {
        if  (q.type == 1) {
            int i = level(q.x);
            first_val[i] -= q.k % size_level(i);
            norm(first_val[i], i);
        } else if  (q.type == 2) {
            int i = level(q.x);
            first_node[i] -= q.k % size_level(i);
            norm(first_node[i], i);
            first_val[i] -= q.k % size_level(i);
            norm(first_val[i], i);
        } else {
            vll ans;
            int i = level(q.x);
            ll v = get_node(q.x, i);
            get_ans(v, i, ans);

            sort(all(ans));
            reverse(all(ans));
            for (ll x : ans) {
                printf("%lld ", x);
            }
            printf("\n");
        }

//        eprintf("now:\n");
//        forn(i, 4) {
//            eprintf("%d: val=%lld, node:%lld\n", i, first_val[i], first_node[i]);
//        }
//        eprintf("\n");
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

#if TEST
    while (1) {
        read();

        double st = gett();

        solve();

        eprintf("got, time: %.10f\n", gett() - st);
    }
#endif

    while (read()) {
        solve();

        printf("\n");
        eprintf("\n");

//        break;
    }

    return 0;
}