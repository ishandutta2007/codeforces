// e-cow-and-treats.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}
ostream& operator<<(ostream& out, const pair<int, pii> o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

/*

*/

const int MN = 5005;
int N, M,
    F[MN], cntF[MN];
vector<pair<int, pii>> cow[MN]; // (hunger, (left id, right id))

pll solve(pair<int, pii> init) {
    auto &pos = init.sn;
    pll res{init.fs != -1, 1LL};
    for (auto i = 1; i <= N; i++) {
        if (cow[i].empty()) continue;
        bool is = false;
        int lcnt = 0, rcnt = 0, bcnt = 0;
        for (auto &c : cow[i]) {
            if (c == init) {
                is = true;
                continue;
            }
            bool lft = c.sn.fs < pos.fs, rht = c.sn.sn > pos.fs;
            if (lft && rht) bcnt++;
            else if (lft) lcnt++;
            else if (rht) rcnt++;
        }

        // cout<<"i="<<(i)<<", "; cout<<"lcnt="<<(lcnt)<<", "; cout<<"rcnt="<<(rcnt)<<", "; cout<<"bcnt="<<(bcnt)<<", "; cout << endl; // db i,lcnt,rcnt,bcnt

        // left and right
        if (!is) {
            if ((lcnt && rcnt) || (lcnt && bcnt) || (bcnt && rcnt) || (bcnt >= 2)) {
                res.fs += 2;
                ll way = mmul(lcnt, rcnt);
                way = madd(way, mmul(lcnt, bcnt));
                way = madd(way, mmul(bcnt, rcnt));
                way = madd(way, bcnt * (bcnt - 1) % MOD);
                res.sn = mmul(res.sn, way);
            }
            // lol only one side
            else if (lcnt || rcnt || bcnt) {
                res.fs++;
                res.sn = mmul(res.sn, lcnt + rcnt + 2 * bcnt);
            }
        }
        else if (rcnt || bcnt) {
            res.fs++;
            res.sn = mmul(res.sn, rcnt + bcnt);
        }
    }
    // cout<<"init="<<(init)<<", "; cout<<"res="<<(res)<<", "; cout << endl; // db init,res
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 1; i <= N; i++) {
        cin >> (F[i]);
        cntF[F[i]]++;
    }
    for (auto i = 0; i < M; i++) {
        int f, h;
        cin >> f >> h;
        int lind = INF, rind = -INF, ccnt = 0;
        for (auto j = 1; j <= N; j++) {
            ccnt += F[j] == f;
            if (ccnt == h) {
                lind = j;
                break;
            }
        }
        ccnt = 0;
        for (auto j = N; j >= 1; j--) {
            ccnt += F[j] == f;
            if (ccnt == h) {
                rind = j;
                break;
            }
        }
        cow[f].eb(h, mpr(lind, rind));
    }

    pll ans{-1, 0}; // (maxGood, ways)
    cow[N + 1].eb(-1, mpr(0, 0));
    for (auto i = 1; i <= N + 1; i++) {
        for (auto &cc : cow[i]) {
            if (cc.sn.fs > N) continue;
            auto res = solve(cc);
            if (res.fs > ans.fs) ans = res;
            else if (res.fs == ans.fs) ans.sn = madd(ans.sn, res.sn);
        }
    }

    cout << (ans.fs) << ' ' << (ans.sn) << '\n';

    return 0;
}