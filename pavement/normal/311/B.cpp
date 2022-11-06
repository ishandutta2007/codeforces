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

int N, M, P, D[100005], A[100005], PA[100005], dp[2][100005];

struct MonotonicLineContainer { // increasing inserts and queries only
    vector<pair<int, int> > D; // use an array as a last resort
    int sf = 0;
    long double is(int a, int b, int c, int d) { // replace with cross-multiplication if no overflow
        return (long double)(d - b) / (a - c);
    }
    void add(int m, int c) { // insert y = mx + c
        if (!D.empty() && D.back().first == m && D.back().second > c) return;
        while (D.size() - sf > 1) {
            int s = D.size();
            if ((D[s - 1].first == m && c > D[s - 1].second) || (is(D[s - 1].first, D[s - 1].second, m, c) <= is(D[s - 2].first, D[s - 2].second, m, c))) D.pop_back();
            else break;
        }
        D.emplace_back(m, c);
    }
    int query(int x) { // max query
        while (D.size() - sf > 1) {
            if (D[sf].first * x + D[sf].second < D[sf + 1].first * x + D[sf + 1].second) sf++;
            else break;
        }
        return D[sf].first * x + D[sf].second;
    }
} hull;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> P;
	for (int i = 2; i <= N; i++) cin >> D[i], D[i] += D[i - 1];
	for (int i = 1, h, t; i <= M; i++) {
		cin >> h >> t;
		A[i] = t - D[h];
	}
	sort(A + 1, A + 1 + M);
	for (int i = 1; i <= M; i++) PA[i] = PA[i - 1] + A[i];
	for (int j = 1; j <= P; j++) {
		hull.D.clear();
		hull.sf = 0;
		for (int i = 1; i <= M; i++) {
			if (j == 1) dp[1][i] = i * A[i] - PA[i];
			else {
				hull.add(i - 1, -PA[i - 1]  + -dp[j & 1 ^ 1][i - 1]);
				// dp[i] = min(-j * A[i] + PA[j] + dp[j]) + i * A[i] - PA[i]
				// dp[i] = -max(j * A[i] - PA[j] - dp[j]) + i * A[i] - PA[i]
				dp[j & 1][i] = -hull.query(A[i]) + i * A[i] - PA[i];
			}
		}
	}
	cout << dp[P & 1][M] << '\n';
}