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

int T, A, B;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> A >> B >> S;
		vector<int> pos;
		bool inv = 0;
		for (char c : S)
			if (c == '1') B--;
			else if (c == '0') A--;
		for (int i = 0; i < S.size(); i++) {
			if (S.size() - i - 1 <= i) break;
			int k = S.size() - i - 1;
			if (S[i] == S[k] && S[i] != '?') continue;
			if (S[i] != '?' && S[k] != '?' && S[i] != S[k]) {
				inv = 1;
				break;
			}
			if (S[i] == S[k]) {
				pos.pb(i);
			} else if (S[i] != '?') {
				if (S[i] == '1') B--;
				else A--;
				S[k] = S[i];
				//cout << "SET " << k << ' ' << S[i] << '\n';
			} else {
				assert(S[k] != '?');
				if (S[k] == '1') B--;
				else A--;
				S[i] = S[k];
			}
			//cout << S[i];
		}
		//cout << A << ' ' << B << '\n';
		for (int i : pos) {
			//cout << "POS " << i << '\n';
			int k = S.size() - i - 1;
			if (A >= 2) S[i] = S[k] = '0', A -= 2;
			else S[i] = S[k] = '1', B -= 2;
		}
		if (S.size() & 1) {
			if (S[S.size() / 2] == '?') {
				if (A) S[S.size() / 2] = '0', A--;
				else S[S.size() / 2] = '1', B--;
			}
		}
		if (A != 0 || B != 0 || inv) cout << "-1\n";
		else cout << S << '\n'; 
	}
}