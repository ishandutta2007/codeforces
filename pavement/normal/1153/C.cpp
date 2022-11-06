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

int N;
string S;
char out[300005];
vector<int> vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	if (N == 1) return cout << ":(\n", 0;
	bool inv = 0;
	if (S[0] == ')') return cout << ":(\n", 0;
	out[0] = '(';
	int cnt = 0;
	for (int i = 1; i < (int)S.size() - 1; i++) {
		if (S[i] == '(') cnt++, out[i] = '(';
		else if (S[i] == ')') {
			cnt--, out[i] = ')';
			if (cnt == -1) {
				if (vec.empty()) return cout << ":(\n", 0;
				out[vec.back()] = '(';
				vec.ppb();
				cnt += 2;
			}
		} else {
			if (cnt) cnt--, out[i] = ')', vec.pb(i);
			else cnt++, out[i] = '(';
		}
		if (cnt < 0) inv = 1;
	}
	inv |= !!cnt;
	out[S.size() - 1] = ')';
	if (S[S.size() - 1] == '(') return cout << ":(\n", 0;
	if (inv) cout << ":(\n";
	else {
		for (int i = 0; i < S.size(); i++) cout << out[i];
		cout << '\n';
	}
}