// ./d1-gregor-and-the-odd-cows-easy.yml
#include <bits/stdc++.h>
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

const int MN = 6001;
int N;
pii ps[MN];

int cntborder(const pii &a, const pii &b) {
    int xd = a.fs-b.fs, yd = a.sn-b.sn;
    return abs(gcd(xd, yd));
}

ll cnt[2][2];
const pii TYPES[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

ll C(ll N, ll K) {
    ll res = 1;
    for (auto i = N; i >= N-K+1; i--)
        res *= i;
    for (auto i = 2; i <= K; i++)
        res /= i;
    return res;
}

int getcnt(const pii &p) {
    return cnt[p.fs][p.sn];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> ps[i].fs >> ps[i].sn;
        ps[i].fs /= 2;
        ps[i].sn /= 2;
        
        cnt[ps[i].fs & 1][ps[i].sn & 1]++;
        // cout<<"ps[i].fs="<<(ps[i].fs)<<", "; cout<<"ps[i].sn="<<(ps[i].sn)<<", "; cout << endl; // db ps[i].fs,ps[i].sn
    }

    ll ans = 0;
    // for (auto i = 0; i < N; i++) {
    //     for (auto j = i+1; j < N; j++) {
    //         for (auto k = j+1; k < N; k++) {
    //             ans += (cntborder(i, j) + cntborder(j, k) + cntborder(i, k)) % 2 == 0;
    //         }
    //     }
    // }
    set<vector<pair<pii, int>>> used;
    for (auto &d1 : TYPES) {
        for (auto &d2 : TYPES) {
            for (auto &d3 : TYPES) {
                int bc = cntborder(d1, d2) + cntborder(d2, d3) + cntborder(d1, d3);
                if (bc % 2 == 0) {
                    map<pii, int> fre;
                    fre[d1]++;
                    fre[d2]++;
                    fre[d3]++;

                    // cout<<"d1="<<(d1)<<", "; cout<<"d2="<<(d2)<<", "; cout<<"d3="<<(d3)<<", "; cout << endl; // db d1,d2,d3

                    vector<pair<pii, int>> curUsed(all(fre));
                    if (used.count(curUsed)) continue;
                    ll cur = 1;
                    for (auto &[k, v] : fre) {
                        ll curcnt = getcnt(k);
                        if (curcnt < v) cur = 0;
                        else cur *= C(curcnt, v);
                    }
                    ans += cur;

                    used.insert(curUsed);
                }
            }
        }
    }
    cout << (ans) << '\n';

    return 0;
}