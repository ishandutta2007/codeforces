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

int N, P, ans = 1e16;
vector<int> vec;

void op1(vector<int> &vec) {
	for (int j = 0; j < vec.size(); j += 2)
		swap(vec[j], vec[j + 1]);
}

void op2(vector<int> &vec) {
	for (int i = 0; i < vec.size() / 2; i++)
		swap(vec[i], vec[i + vec.size() / 2]);
}


void inverse(vector<int> &vec) {
	vector<int> ret(vec.size());
	for (int i = 0; i < vec.size(); i++) ret[vec[i]] = i;
	vec = ret;
}

int comp(vector<int> vec) {
	int n = vec.size();
	vector<int> perm;
	for (int i = 0; i < n; i++) perm.pb(i);
	op1(perm);
	op2(perm);
	inverse(perm);
	int pos = -1, move = 0;
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == 1) pos = i;
	if (pos != 0) {
		int curr = pos;
		do {
			curr = perm[curr];
			move++;
		} while (curr != pos && curr != 0);
		if (curr == pos) return 1e16;
	}
	vector<int> newvec(n);
	for (int i = 0; i < vec.size(); i++) {
		int tmp = i;
		for (int j = 0; j < move; j++) tmp = perm[tmp];
		newvec[tmp] = vec[i];
	}
	if (!is_sorted(newvec.begin(), newvec.end())) return 1e16;
	return move * 2;
}

int comp2(vector<int> vec) {
	int n = vec.size();
	vector<int> perm;
	for (int i = 0; i < n; i++) perm.pb(i);
	op2(perm);
	op1(perm);
	inverse(perm);
	int pos = -1, move = 0;
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == 1) pos = i;
	if (pos != 0) {
		int curr = pos;
		do {
			curr = perm[curr];
			move++;
		} while (curr != pos && curr != 0);
		if (curr == pos) return 1e16;
	}
	vector<int> newvec(n);
	for (int i = 0; i < vec.size(); i++) {
		int tmp = i;
		for (int j = 0; j < move; j++) tmp = perm[tmp];
		newvec[tmp] = vec[i];
	}
	if (!is_sorted(newvec.begin(), newvec.end())) return 1e16;
	return move * 2;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	N *= 2;
	for (int i = 1; i <= N; i++) {
		cin >> P;
		vec.pb(P);
	}
	if (is_sorted(vec.begin(), vec.end())) return cout << "0\n", 0;
	ans = comp(vec); // even number of moves, start from op1
	op2(vec);
	ans = min(ans, comp(vec) + 1); // odd number of moves, start from op2
	op2(vec);
	op1(vec);
	ans = min(ans, comp2(vec) + 1); // odd number of moves, start from op1
	op1(vec);
	ans = min(ans, comp2(vec)); // even number of moves, start from op2
	cout << (ans == 1e16 ? -1 : ans) << '\n';
}