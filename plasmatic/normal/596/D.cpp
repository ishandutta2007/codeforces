// ./d-wilbur-and-trees.yml
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

const int MN = 2001 + 5;
int N, H,
    X[MN], mright[MN], mleft[MN];
ld P,
   dp[2][2][MN][MN]; // 0->left, 1->right

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (H) >> (P);
    for (auto i = 1; i <= N; i++)
        cin >> (X[i]);
    sort(X + 1, X + N + 1);
    X[0] = -INF; X[N+1] = INF;

    // init mright/mleft
    for (auto i = 1; i <= N; i++) {
        for (mright[i] = i; mright[i] < N && X[mright[i] + 1] < X[mright[i]] + H; mright[i]++);
        for (mleft[i] = i; mleft[i] > 1 && X[mleft[i] - 1] > X[mleft[i]] - H; mleft[i]--);
    }

    // do dp
    ld pl = P * 0.5, pr = (1 - P) * 0.5, ans = 0;

    dp[0][0][1][N] = 1.;
    for (int len = N; len >= 1; len--) {
        int end = N - len + 1;
        for (auto i = 0; i < 2; i++) {
            for (auto j = 0; j < 2; j++) {
                for (auto l = 1; l <= end; l++) {
                    int r = l + len - 1;
                    ld cv = dp[i][j][l][r];
                    if (cv == 0 && !(l == 1 && r == N && i == 0 && j == 0)) continue;

                    int lp = X[l - 1] + i * H, rp = X[r + 1] - (j ^ 1) * H;

                    auto getlen = [&] (int l, int r) {
                        return min(r, rp) - max(l, lp);
                    };

                    // cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"dp[i][j][l][r]="<<(dp[i][j][l][r])<<", "; cout << endl; // db l,r,i,j,dp[i][j][l][r]

                    if (l < r) {
                        // knock leftmost
                        int npos = min(r, mright[l]);
                        dp[0][j][l + 1][r] += pl * cv; // left
                        dp[1][j][npos + 1][r] += pr * cv; // right
                        ans += pl * cv * getlen(X[l] - H, X[l]);
                        ans += pr * cv * getlen(X[l], X[npos] + H);
                        
                        // knock rightmost
                        npos = max(l, mleft[r]);
                        dp[i][0][l][npos - 1] += pl * cv;
                        dp[i][1][l][r - 1] += pr * cv;
                        ans += pl * cv * getlen(X[npos] - H, X[r]);
                        ans += pr * cv * getlen(X[r], X[r] + H);
                    }
                    else {
                        ans += P * cv * getlen(X[l] - H, X[l]);
                        ans += (1 - P) * cv * getlen(X[l], X[l] + H);
                        // cout<<"P="<<(P)<<", "; cout<<"cv="<<(cv)<<", "; cout<<"getlen(X[l], X[l]+H)="<<(getlen(X[l], X[l]+H))<<", "; cout<<"getlen(X[l]-H,X[l])="<<(getlen(X[l]-H,X[l]))<<", "; cout << endl; // db P,cv,getlen(X[l], X[l]+H), getlen(X[l]-H,X[l])
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}