// ./d2-frequency-problem-hard-version.yml
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

string __(vector<int> v) {
    string res = "[";
    for (auto x : v) res += to_string(x) + ", ";
    return res + "]";
}
#define _(x) (__(x).c_str())

const int MN = 2e5 + 10, MB = 450/2;
int N, 
    val[MN];
vector<int> idx[MN];

int nxtM[MN], preM[MN];

const int _DEF = -1, D = 2e5;
struct fca {
    int a[MN*2], qid[MN*2], cqid = 1, rs;
    int& operator[](int i) {
        i += D;
        if (qid[i] != cqid) {
            qid[i] = cqid;
            a[i] = _DEF;
        }
        return a[i];
    }
    void reset() { cqid++; }
};
fca fst;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    vector<int> fre(N+1);
    for (auto i = 1; i <= N; i++) {
        cin >> val[i];
        fre[val[i]]++;
        idx[val[i]].push_back(i);
    }
    int mfre = *max_element(fre.begin(), fre.end()), biggest = -1;
    for (auto i = 1; i <= N; i++) {
        if (fre[i] == mfre) {
            if (biggest == -1) biggest = i;
            else {
                cout << N << "\n";
                return 0;
            }
        }
    }

    // set up pre/nxt arrays
    for (auto i = 1; i <= N; i++)
        preM[i] = val[i] == biggest ? i : preM[i-1];
    nxtM[N+1] = N+1;
    for (auto i = N; i >= 1; i--)
        nxtM[i] = val[i] == biggest ? i : nxtM[i+1];

    // ans
    int ans = 0;
    for (auto i = 1; i <= N; i++) {
        if (i == biggest) continue;

        if (fre[i] >= MB) {
            vector<int> psum(N+1), fst(2*N+1, -1), lst(2*N+1, -1);
            int D = N;
            fst[D] = 0;

            for (auto j = 1; j <= N; j++) {
                psum[j] = psum[j-1];
                if (val[j] == biggest) psum[j]--;
                else if (val[j] == i) psum[j]++;
                if (fst[psum[j]+D] == -1) fst[psum[j]+D] = j;
            }
            for (auto j = N; j >= 1; j--)
                if (lst[psum[j]+D] == -1)
                    lst[psum[j]+D] = j;
            for (auto j = 0; j <= 2*N; j++)
                if (fst[j] != -1 && lst[j] != -1 && fst[j] != lst[j])
                    ans = max(ans, lst[j] - fst[j]);
        }
        else {
            int cnt = fre[i]+2;
            for (auto j = 0; j < (int)idx[i].size(); j++) {
                int st = idx[i][j];

                int c = preM[st], ptr = 0;
                for (int left = cnt; c > 0 && left > 0; left--, c = preM[c-1]);

                vector<int> important;
                while (ptr < (int)idx[i].size() && idx[i][ptr] < c) ptr++;
                for (int left = cnt*2; c <= N && left > 0; left--, c = nxtM[c+1]) {
                    while (ptr < (int)idx[i].size() && idx[i][ptr] < c) {
                        important.push_back(idx[i][ptr]);
                        ptr++;
                    }
                    important.push_back(c);
                }
                while (ptr < (int)idx[i].size() && idx[i][ptr] < c) {
                    important.push_back(idx[i][ptr]);
                    ptr++;
                }
                if (c > N)
                    important.push_back(N+1);
                
                vector<int> ival(important.size());
                fst.reset();
                int csum = 0, pre = important[0]-1, cidx = 0;
                for (auto k : important) {
                    if (1 <= k && k <= N) {
                        if (val[k] == i) csum++;
                        else if (val[k] == biggest) csum--;
                    }
                    ival[cidx++] = csum;

                    if (fst[csum] == -1) {
                        fst[csum] = k;
                    }

                    pre = k;
                }

                pre = important.back();
                for (int ridx = important.size()-1; ridx >= 0; ridx--) {
                    int k = important[ridx], csum = ival[ridx];

                    if (pre > k && fst[csum] != k) {
                        int clst = pre-1;
                        ans = max(ans, clst - fst[csum]);
                    }

                    pre = k;
                }
            }
        }
    }

    cout << (ans) << '\n';

    return 0;
}