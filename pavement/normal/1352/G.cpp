#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, A[] = {-1, 2, 4, 1, 3}, A5[] = {-1, 3, 1, 4, 2, 5}, A6[] = {-1, 1, 3, 5, 2, 4, 6}, A7[] = {-1, 1, 3, 5, 2, 6, 4, 7};

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		if (N <= 3) {
			cout << "-1\n";
		} else if (N % 4 == 0) {
			for (int i = 1; i <= N / 4; i++)
				for (int j = 1; j <= 4; j++)
					cout << A[j] + (i - 1) * 4 << ' ';
			cout << '\n';
		} else if (N % 4 == 1) {
			for (int i = 1; i <= N / 4 - 1; i++)
				for (int j = 1; j <= 4; j++)
					cout << A[j] + (i - 1) * 4 << ' ';
			for (int i = 1; i <= 5; i++) cout << A5[i] + (N / 4 - 1) * 4 << ' ';
			cout << '\n';
		} else if (N % 4 == 2) {
			for (int i = 1; i <= N / 4 - 1; i++)
				for (int j = 1; j <= 4; j++)
					cout << A[j] + (i - 1) * 4 << ' ';
			for (int i = 1; i <= 6; i++) cout << A6[i] + (N / 4 - 1) * 4 << ' ';
			cout << '\n';
		} else if (N % 4 == 3) {
			for (int i = 1; i <= N / 4 - 1; i++)
				for (int j = 1; j <= 4; j++)
					cout << A[j] + (i - 1) * 4 << ' ';
			for (int i = 1; i <= 7; i++) cout << A7[i] + (N / 4 - 1) * 4 << ' ';
			cout << '\n';
		}
	}
}