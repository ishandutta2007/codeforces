// ./bobs-xor-sequence.yml
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
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct Qu {
    int i, l, r, bl;
    bool operator<(const Qu &o) const {
        return bl == o.bl ? r < o.r : bl < o.bl;
    }
};

ostream& operator<<(ostream& out, const Qu o) {
    out << "(i=" << o.i << ", l=" << o.l << ", r=" << o.r << ", bl=" << o.bl << ")";
    return out;
}

const int MN = 1e5 + 1, MX = 1<<20, B = 320;
int N, K, Q,
    val[MN];
ll ans[MN];
Qu qus[MN];

// maintain pointers
int shPre = 0, shSuf = 0,
    cntPre[MX], cntSuf[MX];
deque<int> pre, suf;
ll cans = 0;

int BB(deque<int> &x) { return x.empty() ? 0 : x.back(); }
int FF(deque<int> &x) { return x.empty() ? 0 : x.front(); }
void ins(int x, bool bk) {
    if (bk) {
        cntSuf[shSuf]++; suf.pb(shSuf);
        shSuf ^= x;
        cans += cntSuf[K ^ shSuf];
        // cout<<"x="<<(x)<<", "; cout << "suf=["; for (auto x:suf)cout<<x<<", "; cout<<"], "; cout<<"shSuf="<<(shSuf)<<", "; cout << "pre=["; for (auto x:pre)cout<<x<<", "; cout<<"], "; cout<<"shPre="<<(shPre)<<", "; cout<<"cans="<<(cans)<<", "; cout << endl; // db x,I:suf,shSuf,I:pre,shPre,cans

        pre.pb(BB(pre) ^ x); cntPre[BB(pre)]++;
    }
    else {
        cntPre[shPre]++; pre.push_front(shPre);
        shPre ^= x;
        cans += cntPre[K ^ shPre];

        suf.push_front(FF(suf) ^ x); cntSuf[FF(suf)]++;
    }
}
void rem(int x, bool bk) {
    if (bk) {
        cans -= cntSuf[K ^ shSuf];
        cntSuf[BB(suf)]--; suf.pop_back();
        shSuf ^= x;

        cntPre[BB(pre)]--; pre.pop_back();
    }
    else {
        cans -= cntPre[K ^ shPre];
        cntPre[FF(pre)]--; pre.pop_front();
        shPre ^= x;

        cntSuf[FF(suf)]--; suf.pop_front();

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (Q) >> (K);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);
    for (auto i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        qus[i] = {i, l, r, l / B};
    }
    sort(qus, qus + Q);
    // for (auto i = 1; i <= N; i++)
    //     val[i] ^= val[i - 1];

    // cntPre[0] = cntSuf[0] = 1;
    int l = 1, r = 0;
    for (auto i = 0; i < Q; i++) {
        auto &q = qus[i];
        while (r < q.r) ins(val[++r], 1);
        while (l > q.l) ins(val[--l], 0);
        while (r > q.r) rem(val[r--], 1);
        while (l < q.l) rem(val[l++], 0);

        // cout<<"i="<<(i)<<", "; cout<<"q="<<(q)<<", "; cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"cans="<<(cans)<<", "; cout << endl; // db i,q,l,r,cans
        // cout<<"cntPre=["; for(int i=0; i<(8); i++)cout<<cntPre[i]<<", "; cout<<"], ";cout<<"shPre="<<(shPre)<<", "; cout<<"cntSuf=["; for(int i=0; i<(8); i++)cout<<cntSuf[i]<<", "; cout<<"], ";cout<<"shSuf="<<(shSuf)<<", "; cout << "pre=["; for (auto x:pre)cout<<x<<", "; cout<<"], "; cout << "suf=["; for (auto x:suf)cout<<x<<", "; cout<<"], "; cout << endl; // db A:8:cntPre,shPre,A:8:cntSuf,shSuf,I:pre,I:suf
        ans[q.i] = cans;
    }

    for (auto i = 0; i < Q; i++)
        cout << (ans[i]) << '\n';

    return 0;
}