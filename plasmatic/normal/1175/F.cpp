// ./f-the-number-of-subpermutations.yml
#include <bits/stdc++.h>
#define DEBUG 0
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

const int MN = 3e5 + 1;
int N,
    A[MN];

ll ans = 0;

// DS
int fre[MN], good = 0, sz = 0;

int _getGood(int x) { return fre[x] == 1; }
void extendSz(int nsz) {
    while (sz < nsz) {
        sz++;
        good += _getGood(sz);
    }
}
void change(int x, int d) {
    int delta = -_getGood(x);
    fre[x] += d;
    delta += _getGood(x);
    if (x <= sz) good += delta;
    if (DEBUG) { cout<<"[upd]: "; cout<<"x="<<(x)<<", "; cout<<"d="<<(d)<<", "; cout<<"delta="<<(delta)<<", "; cout<<"fre[x]-d="<<(fre[x]-d)<<", "; cout<<"fre[x]="<<(fre[x])<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db l:upd,x,d,delta,fre[x]-d,fre[x]
}
bool ok() { return good == sz; }

void reset(vector<int> v) {
    good = 0;
    sz = 0;

    for (auto x : v) fre[x] = 0;
}

vector<int> ind1;

// end DS

void compute(vector<int> lhs, vector<int> rhs) {
    int s1 = SZ(lhs), s2 = SZ(rhs), lptr = 0;

    if (DEBUG) { cout << "lhs=["; for (auto __x:lhs)cout<<__x<<", "; cout<<"], "; cout << "rhs=["; for (auto __x:rhs)cout<<__x<<", "; cout<<"], "; cout << endl; } //__RAW_DEBUG_LINE__:db I:lhs,I:rhs
    // if (DEBUG) { cout<<"good="<<(good)<<", "; cout<<"sz="<<(sz)<<", "; cout<<"fre=["; for(int __i=0; __i<(5); __i++)cout<<(fre)[__i]<<", "; cout<<"], ";cout << endl; } //__RAW_DEBUG_LINE__:db good,sz,A:5:fre

    int dans = ans;
    for (auto i = 0; i < s2; i++) {
        extendSz(rhs[i]);
        assert(rhs[i] <= sz);
        change(rhs[i], 1);

        if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"rhs[i]="<<(rhs[i])<<", "; cout<<"good="<<(good)<<", "; cout<<"sz="<<(sz)<<", "; cout << "lhs=["; for (auto __x:lhs)cout<<__x<<", "; cout<<"], "; cout<<"lptr="<<(lptr)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,rhs[i],good,sz,I:lhs,lptr

        while (lptr < s1 && (i+1) + lptr < sz) {
            change(lhs[lptr], 1);
            lptr++;
        }
        while (lptr > 0 && (i+1) + lptr > sz) {
            lptr--;
            change(lhs[lptr], -1);
        }

        if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"rhs[i]="<<(rhs[i])<<", "; cout<<"good="<<(good)<<", "; cout<<"sz="<<(sz)<<", "; cout << "lhs=["; for (auto __x:lhs)cout<<__x<<", "; cout<<"], "; cout<<"lptr="<<(lptr)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,rhs[i],good,sz,I:lhs,lptr

        ans += ok();
    }
    if (DEBUG) { cout<<"ans-dans="<<(ans-dans)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db ans-dans

    reset(lhs); reset(rhs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    ind1.pb(-1);
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 1)
            ind1.pb(i);
    }
    ind1.pb(N);

    for (auto i = 1; i < SZ(ind1)-1; i++) {
        int p = ind1[i-1], c = ind1[i], n = ind1[i+1];

        if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"p="<<(p)<<", "; cout<<"c="<<(c)<<", "; cout<<"n="<<(n)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,p,c,n
        vector<int> lhs(A+p+1, A+c), rhs(A+c, A+n);
        reverse(all(lhs));
        compute(lhs, rhs);
        lhs = vector<int>(A+c+1, A+n);
        rhs = vector<int>(A+p+1, A+c+1);
        reverse(all(rhs));
        compute(lhs, rhs);

        ans--; // middle 1 gets counted twice
    }

    cout << (ans) << '\n';

    return 0;
}