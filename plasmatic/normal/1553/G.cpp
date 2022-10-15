// ./g-common-divisor-graph.yml
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

struct DSU {
    vector<int> dsu;
    void init(int N) {
        dsu.resize(N + 1);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
    void merge(int x, int y) { // x -> y
        dsu[rt(x)] = rt(y); }
    bool con(int x, int y) { return rt(x) == rt(y); }
};

const int MN = 150011, MV = 1e6 + 100, MNODE = 2*MN;
int N, Q,
    A[MN];
vector<int> prs[MN];

vector<int> pr;
int jmp[MV], idx[MV];
DSU pd;
int dsuId[MV];

// primes ONLY !!! 
vector<int> adjs[MV], hasPrime[MV];

void pf(int k, vector<int> &res) {
    for (auto c = k; c != 1; c /= jmp[c])
        res.pb(jmp[c]);
    UNIQUE(res);
}

bool has(vector<int> &vec, int k) {
    auto ptr = lower_bound(all(vec), k);
    return ptr != vec.end() && *ptr == k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    // sieve
    pr.pb(-1);
    iota(jmp, jmp+MV, 0);
    for (auto i = 2; i < MV; i++) {
        if (jmp[i] == i) {
            for (auto j = i*2; j < MV; j += i)
                jmp[j] = i;
            pr.pb(i);
        }
    }
    memset(idx, -1, sizeof idx);
    for (auto i = 1; i < SZ(pr); i++)
        idx[pr[i]] = i;

    int prsz = SZ(pr)-1;
    pd.init(N+prsz+100);

    // actual input
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];

        pf(A[i], prs[i]);

        for (auto p : prs[i]) {
            pd.merge(i, N+idx[p]);
            hasPrime[p].pb(A[i]);

            // cout<<"i="<<(i)<<", "; cout<<"A[i]="<<(A[i])<<", "; cout<<"p="<<(p)<<", "; cout<<"idx[p]="<<(idx[p])<<", "; cout<<"N+idx[p]="<<(N+idx[p])<<", "; cout << endl; // db i,A[i],p,idx[p],N+idx[p]
        }
    }

    // adj primes
    for (auto p : pr) {
        if (p == -1) continue;
        // if (N+idx[p] >= pd.dsu.size()) {
        //     cout<<"N+idx[p]="<<(N+idx[p])<<", "; cout<<"pd.dsu.size()="<<(pd.dsu.size())<<", "; cout << endl; // db N+idx[p],pd.dsu.size()
        //     cout<<"p="<<(p)<<", "; cout << endl; // db p
        // }
        dsuId[p] = pd.rt(N+idx[p]);
    }
    // assert(0);
    for (auto p : pr) {
        if (p == -1) continue;
        UNIQUE(hasPrime[p]);

        auto &vec = adjs[dsuId[p]];
        for (auto v : hasPrime[p]) {
            vector<int> toAdd;
            pf(v+1, toAdd);
            for (auto &vv : toAdd) vv = dsuId[vv];
            vec.insert(vec.end(), all(toAdd));
        }
    }

    for (int i = 1; i <= N; i++) {
        vector<int> cur;
        pf(A[i]+1, cur);
        vector<int> cur2 = cur;
        for (auto &pp : cur2) pp = dsuId[pp];
        for (auto p : cur) {
            adjs[dsuId[p]].insert(adjs[dsuId[p]].end(), all(cur2));
        }
    }

    for (auto i = 1; i < MV; i++)
        if (!adjs[i].empty())
            UNIQUE(adjs[i]);

    // answer queries
    while (Q--) {
        int u, v; cin >> u >> v;

        if (pd.con(u, v)) {
            cout << (0) << '\n';
        }
        else {
            int uo = A[u] & 1, vo = A[v] & 1, most = uo + vo;
            if (most <= 1)
                cout << (1) << '\n';
            else { // most == 2
                bool found = false;
                for (auto i = 0; i < 2; i++) {
                    for (auto p1 : prs[u]) {
                        auto &cur = adjs[dsuId[p1]];
                        for (auto p2 : prs[v]) {
                            // cout<<"p1="<<(p1)<<", "; cout<<"p2="<<(p2)<<", "; cout << "cur=["; for (auto __x:cur)cout<<__x<<", "; cout<<"], "; cout << endl; // db p1,p2,I:cur
                            if (has(cur, dsuId[p2])) {
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }

                    swap(u, v);
                }

                cout << (2-found) << '\n';
            }
        }
    }

    return 0;
}