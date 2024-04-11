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

int A, B, K;
bool a[200005], b[200005], used[200005];
set<int> pos;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> K;
	for (int i = 1; i <= B; i++) b[i] = 1;
	for (int i = B + 1; i <= B + A; i++) b[i] = 0;
	for (int i = 1; i <= B + A; i++) {
		a[i] = b[i];
		if (a[i]) pos.insert(i);
	}
	int curend = A + B;
	for (int i = 1; i <= K; i++) {
		int it = *(--pos.end());
		while (it == curend) {
			pos.erase(--pos.end());
			curend--;
			if (pos.empty()) return cout << "No\n", 0;
			it = *(--pos.end());
		}
		if (!used[it]) {
			a[it + 1] = 1;
			a[it] = 0;
			used[it] = 1;
			pos.erase(--pos.end());
			pos.insert(it + 1);
		} else {
			pos.erase(--pos.end());
			if (pos.empty()) return cout << "No\n", 0;
			i--;
		}
	}
	if (!a[1]) return cout << "No\n", 0;
	cout << "Yes\n";
	for (int i = 1; i <= A + B; i++) cout << b[i];
	cout << '\n';
	for (int i = 1; i <= A + B; i++) cout << a[i];
	cout << '\n';
}