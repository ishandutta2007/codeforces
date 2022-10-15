// ./g-monsters-and-potions.yml
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

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

const int MN = 101;
const pii INIT = mpr(-1, -1), BAD = mpr(-2, -2), BASE = mpr(0, 0);
int N, M,
    cost[MN], mcost[MN][MN];
pii dp[MN][MN];
int hero[MN], heroId[MN];

pii solve(int l, int r) {
    if (l > r) return BASE;
    if (dp[l][r] != INIT) return dp[l][r];
    pii res = BAD;
    for (auto i = l; i <= r; i++) { // Occupy range: L..R
        if (hero[l] != -1 && hero[l] + mcost[l][i] >= 0 && solve(i + 1, r) != BAD)
            maxa(res, mpr(i + 1, r));
        if (hero[r] != -1 && hero[r] + mcost[r][i] >= 0 && solve(l, i - 1) != BAD)
            maxa(res, mpr(l, i - 1));
        // if (l==4&&r==6) {
        //     cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"i="<<(i)<<", "; cout<<"hero[l]="<<(hero[l])<<", "; cout<<"mcost[l][i]="<<(mcost[l][i])<<", "; cout << endl; // db l,r,i,hero[l],mcost[l][i]
        //     cout<<"hero[r]="<<(hero[r])<<", "; cout<<"mcost[r][i]="<<(mcost[r][i])<<", "; cout << endl; // db hero[r],mcost[r][i]
        //     cout<<"solve(i+1,r)="<<(solve(i+1,r))<<", "; cout<<"solve(l,i-1)="<<(solve(l,i-1))<<", "; cout << endl; // db solve(i+1,r),solve(l,i-1)
        // }
    }
    return dp[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    memset(hero, -1, sizeof hero);
    memset(heroId, -1, sizeof heroId);
    for (auto i = 1; i <= M; i++) {
        int p, s;
        cin >> p >> s;
        hero[p] = s;
        heroId[p] = i;
    }
    for (auto i = 1; i <= N; i++)
        cin >> (cost[i]);
    for (auto i = 1; i <= N; i++) {
        int csum = 0, cmin = INF;
        for (auto j = i; j <= N; j++) {
            csum += cost[j];
            mina(cmin, csum);
            mcost[i][j] = cmin;
        }
        csum = 0; cmin = INF;
        for (auto j = i; j >= 1; j--) {
            csum += cost[j];
            mina(cmin, csum);
            mcost[i][j] = cmin;
        }
    }

    for (auto i = 1; i <= N; i++)
        for (auto j = 1; j <= N; j++)
            dp[i][j] = INIT;
    int lb = -1, rb = -1;
    for (auto i = 1; i <= N; i++) {
        if (hero[i] != -1) {
            if (lb == -1) lb = i;
            rb = i;
        }
    }

    pii ans = solve(lb, rb);
    if (ans == BAD)
        cout << (-1) << '\n';
    else {
        pii cur = mpr(lb, rb);
        int st = -1;
        vector<int> horder;
        while (cur.fs <= cur.sn) {
            auto nxt = dp[cur.fs][cur.sn];
            if (cur.fs != nxt.fs) {
                horder.pb(heroId[cur.fs]);
                if (nxt.fs > nxt.sn)
                    st = nxt.sn;
            }
            else if (cur.sn != nxt.sn) {
                horder.pb(heroId[cur.sn]);
                if (nxt.sn < nxt.fs)
                    st = nxt.fs;
            }
            cur = nxt;
        }
        reverse(all(horder));
        for (auto i = 1; i <= M; i++)
            if (find(all(horder), i) == horder.end())
                horder.pb(i);

        cout << (st) << '\n';
        for (auto x : horder)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}