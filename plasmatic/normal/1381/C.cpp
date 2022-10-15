// ./c-mastermind.yml
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
// // PBDS order statistic tree
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds; 
// template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// // HashSet
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
// template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
// template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
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

const int MN = 1e5 + 1;
int N, X, Y,
    B[MN];

pair<bool, vector<int>> getAns(int N, int X, int Y, int bad, vector<int> B) {
    if (N == 0) return mpr(true, vector<int>());
    // cout<<"N="<<(N)<<", "; cout<<"X="<<(X)<<", "; cout<<"Y="<<(Y)<<", "; cout << endl; // db N,X,Y
    int right = X, permc = Y-X;
    assert(right >= 0 && permc >= 0 && N >= 0);

    // make fre array/etc.
    map<int, vector<int>> idx; // highest freq first
    for (auto i = 0; i < N; i++)
        idx[B[i]].pb(i);
    set<pii, greater<pii>> freSet;
    for (auto &p : idx)
        freSet.emplace(SZ(p.sn), p.fs);

    // Remove N-(Y-X) of the indices
    vector<int> permInd, othInd;
    for (auto i = 0; i < N-(Y-X); i++) {
        assert(!freSet.empty());
        auto b = *freSet.begin(); freSet.erase(freSet.begin());

        assert(b.fs>0);

        // cout<<"i="<<(i)<<", "; cout<<"b="<<(b)<<", "; cout << "idx[b.sn]=["; for (auto __x:idx[b.sn])cout<<__x<<", "; cout<<"], "; cout << endl; // db i,b,I:idx[b.sn]
        assert(!idx[b.sn].empty());
        othInd.pb(idx[b.sn].back());
        idx[b.sn].pop_back();

        b.fs--;
        freSet.insert(b);
    }
    for (auto &p : idx)
        permInd.insert(permInd.end(), all(p.sn));

    // set up fre array for Y-X permc values
    vector<int> fre(N+50, 0);
    for (auto i : permInd)
        fre[B[i]]++;

    // set up Y-X permc values
    vector<pii> vs;
    for (auto i : permInd)
        vs.eb(B[i], i);
    sort(all(vs), [&] (const pii a, const pii b) {
        return fre[a.fs] == fre[b.fs] ? a.fs < b.fs : fre[a.fs] > fre[b.fs];
    });
    deque<pii> vs2(all(vs));
    if (!vs.empty() && !vs2.empty()) {
        int highest = vs[0].fs;
        for (auto i = 0; i < N; i++) { // only do this up to N times in case theres only one number in the entire array :P
            if (vs2.front().fs == highest) {
                auto fr = vs2.front();
                vs2.pop_front();
                vs2.pb(fr);
            }
        }
    }
    // cout << "vs=["; for (auto __x:vs)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:vs
    // cout << "vs2=["; for (auto __x:vs2)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:vs2

    // check if answer exists
    assert(SZ(vs) == permc && SZ(vs2) == permc);
    for (auto i = 0; i < permc; i++)
        if (vs[i].fs == vs2[i].fs) // I-i-it's too much!!!
            return mpr(false, vector<int>());

    // construct answer
    vector<int> ans(N, bad);
    for (auto i = 0; i < right; i++) {
        assert(0 <= othInd[i] && othInd[i] < SZ(ans));
        assert(0 <= othInd[i] && othInd[i] < SZ(B));
        ans[othInd[i]] = B[othInd[i]];
    }
    for (auto i = 0; i < permc; i++) {
        assert(0 <= vs[i].sn && vs[i].sn < SZ(ans));
        ans[vs[i].sn] = vs2[i].fs;
    }
    // cout << "ans=["; for (auto __x:ans)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:ans
    return mpr(true, ans);
}

void solve() {
    cin >> (N) >> (X) >> (Y);
    unordered_set<int> us; for (int i = 1; i <= N+1; i++) us.insert(i);
    for (auto i = 0; i < N; i++) {
        cin >> B[i];
        if (us.count(B[i]))
            us.erase(B[i]);
    }
    int bad = *us.begin();

    // if it fails, try, try again <3
    auto res = getAns(N, X, Y, bad, vector<int>(B, B + N));
    if (!res.fs && N > Y && Y > X) {
        int find = -1;
        for (auto i = 1; i < N; i++) {
            if (B[i] != B[0]) {
                find = i;
                break;
            }
        }
        if (find != -1) {
            vector<int> v;
            for (auto i = 1; i < N; i++)
                if (i != find) v.pb(B[i]);
            // cout<<"[doingit]: "; cout << endl; // db l:doingit
            auto res2 = getAns(N-2, X, Y-1, bad, v);

            if (res2.fs) {
                res = res2;
                res.sn.insert(res.sn.begin(), bad);
                assert(find <= SZ(res.sn));
                res.sn.insert(res.sn.begin() + find, B[0]);
            }
        }
    }

    if (!res.fs) cout << "NO\n";
    else {
        cout << ("YES") << '\n';
        for (auto x : res.sn) { cout << x << ' '; assert(1 <= x && x <= N+1); }
        cout << '\n';
    }
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}