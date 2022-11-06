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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N;
char out[200005], c[200005];
vector<int> vec, vec2;

bool valid(string S) {
	int cnt = 0;
	for (char c : S)
		if (c == '(') cnt++;
		else if (cnt == 0) return 0;
		else cnt--;
	return cnt == 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int cnt1 = 0, cnt2 = 0, curr = 0;
		vec.clear();
		vec2.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> c[i];
			if (c[i] == '0') {
				while (!cnt1 && !cnt2) {
					if (!curr) break;
					out[vec.back()] = '(';
					vec2.pb(vec.back());
					vec.ppb();
					cnt1 += 2, cnt2 += 2;
					curr--;
				}
				if (cnt1 < cnt2) cnt1++, cnt2--, out[i] = '(';
				else cnt1--, cnt2++, out[i] = ')';
			} else {
				if (cnt1 && cnt2) {
					curr++;
					out[i] = ')';
					vec.pb(i);
					cnt1--;
					cnt2--;
				} else {
					out[i] = '(', cnt1++, cnt2++;
					if (cnt1 - 2 >= 0 && cnt2 - 2 >= 0) vec2.pb(i);
				}
			}
		}
		while (cnt1 > 0 || cnt2 > 0) {
			if (vec2.empty()) break;
			out[vec2.back()] = ')';
			vec.ppb();
			cnt1 -= 2;
			cnt2 -= 2;
		}
		string tmp, tmp2;
		for (int i = 1; i <= N; i++) {
			tmp.pb(out[i]);
			if (c[i] == '1') tmp2.pb(out[i]);
			else tmp2.pb(out[i] == '(' ? ')' : '(');
		}
		if (valid(tmp) && valid(tmp2)) {
			cout << "YES\n";
			cout << tmp << '\n' << tmp2 << '\n';
		} else cout << "NO\n";
	}
}