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

int T, ft[100005];
string A;
map<char, vector<int> > vec;

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p) {
	for (; p <= A.size(); p += ls(p)) ft[p]++;
}

int cost(vector<int> &seq) {
	int cst = 0;
	for (int i = 1; i <= seq.size(); i++) ft[i] = 0;
	for (int i = (int)seq.size() - 1; i >= 0; i--) {
		cst += qry(seq[i] + 1);
		upd(seq[i] + 1);
	}
	return cst;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> A;
		vec.clear();
		for (int i = 0; i < A.size(); i++) {
			vec[A[i]].pb(i);
		}
		int cst = 0;
		vector<int> ans, perm;
		perm.pb('A');
		perm.pb('N');
		perm.pb('O');
		perm.pb('T');
		do {
			vector<int> seq;
			for (int i = 0; i < perm.size(); i++)
				for (int j = 0; j < vec[perm[i]].size(); j++)
					seq.pb(vec[perm[i]][j]);
			if (cost(seq) >= cst) {
				cst = cost(seq);
				ans = seq;
			}
		} while (next_permutation(perm.begin(), perm.end()));
		for (int i : ans) cout << A[i];
		cout << '\n';
	}
}