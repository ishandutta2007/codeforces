#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, ans = LLONG_MAX;
vector<int> v0, v1, v2;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1, T, A, B; i <= N; i++) {
        cin >> T >> A >> B;
        if (A && B) v0.pb(T);
        else if (A) v1.pb(T);
        else if (B) v2.pb(T);
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    partial_sum(v1.begin(), v1.end(), v1.begin());
    partial_sum(v2.begin(), v2.end(), v2.begin());
    for (int i = 0, curr = 0; i <= min(K, (int)v0.size()); i++) {
        if (i > 0) curr += v0[i - 1];
        if (K - i <= min(v1.size(), v2.size())) ans = min(ans, curr + (K - i - 1 >= 0 ? v1[K - i - 1] : 0) + (K - i - 1 >= 0 ? v2[K - i - 1] : 0));
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}