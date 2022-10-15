// ./e-new-year-and-castle-construction.yml
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

struct Pt {
    ll x, y;

    Pt sub(Pt &o) {
        return {x - o.x, y - o.y};
    }
    Pt neg() {
        return {-x, -y};
    }
    ll cross(Pt o) {
        return x * o.y - y * o.x;
    }
};

ostream& operator<<(ostream& out, const Pt o) {
    out << "(x=" << o.x << ", y=" << o.y << ")";
    return out;
}

istream& operator>>(istream &in, Pt &o) {
    in >> o.x >> o.y;
    return in;
}

const int MN = 2501;
int N;
Pt pts[MN];

ll C(int n, int k) {
    ll up = 1, down = 1;
    for (auto i = 1; i <= k; i++) {
        up *= n - i + 1;
        down *= i;
    }
    return up / down;
}

int succ(int x, int N) { x++;
    return x == N ? 0 : x; }
int prec(int x, int N) { x--;
    return x == -1 ? N - 1 : x; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < N; i++)
        cin >> (pts[i]);

    ll totEdge = 0, totSub = C(N, 5);
    for (auto i = 0; i < N; i++) {
        vector<int> ord;
        for (auto j = 0; j < N; j++)
            if (j != i)
                ord.pb(j);
        // assume we start at pt 0 (or 1 when i=0)
        sort(all(ord), [&] (const int a, const int b) {
            auto p1 = pts[a].sub(pts[i]), p2 = pts[b].sub(pts[i]);
            bool anx = p1.x < 0 || (p1.x == 0 && p1.y < 0), bnx = p2.x < 0 || (p2.x == 0 && p2.y < 0);
            if (anx != bnx) return anx < bnx;
            return pts[a].sub(pts[i]).cross(pts[b].sub(pts[i])) < 0;
        });

        // cout<<"i="<<(i)<<", "; cout << "ord=["; for (auto x:ord)cout<<x<<", "; cout<<"], "; cout << endl; // db i,I:ord

        int sz = SZ(ord), r = -1, cnt = 0;
        for (auto l = 0; l < sz; l++) {
            Pt ref = pts[ord[l]].sub(pts[i]);
            while (r + 1 < l + sz && ref.cross(pts[ord[(r + 1) % sz]].sub(pts[i])) <= 0) {
                r++; cnt++;
                // cout<<"i="<<(i)<<", "; cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"pts[ord[l]]="<<(pts[ord[l]])<<", "; cout<<"pts[ord[r]]="<<(pts[ord[r]])<<", "; cout<<"cnt="<<(cnt)<<", "; cout << endl; // db i,l,r,pts[ord[l]],pts[ord[r]],cnt
            }

            // cout<<"i="<<(i)<<", "; cout<<"l="<<(l)<<", "; cout<<"pts[l]="<<(pts[l])<<", "; cout<<"cnt="<<(cnt)<<", "; cout << endl; // db i,l,pts[l],cnt
            if (cnt - 1 >= 3)
                totEdge += C(cnt - 1, 3);
            cnt--;
        }
    }

    ll ans = -(totEdge - 5 * totSub);
    cout << (ans) << '\n';

    return 0;
}