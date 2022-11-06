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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N;
vector<int> T;

string ask(vector<int> v) {
	string r;
	cout << "? " << v.size() << ' ';
	for (int i : v) cout << i << ' ';
	cout << '\n';
	fflush(stdout);
	cin >> r;
	return r;
}

vector<int> brute(int x, int bits) {
	if (bits == 1) {
		vector<int> ret;
		ret.pb(0);
		ret.pb(1);
		return ret;
	}
	vector<int> ret = brute(x, bits - 1), to_add;
	for (int i : ret)
		if ((x ^ i) & (1 << (bits - 2))) to_add.pb(i ^ (x & (1 << (bits - 1))));
		else {
			to_add.pb(i);
			to_add.pb(i ^ (1 << (bits - 1)));
		}
	return to_add;
}

void recur(vector<int> E) {
	//~ cout << "@ ";
	//~ for (int i : E) cout << i << ' ';
	//~ cout << '\n';
	if (E.size() == 3) {
		string str;
		vector<ii> v;
		for (int i = 0; i < 3; i++) v.eb(E[i], i), v.eb(E[i], i);
		for (auto i : v) {
			cout << "? 1 " << i.first << '\n';
			fflush(stdout);
			cin >> str;
			if (str == "YES") {
				cout << "! " << i.first << '\n';
				cin >> str;
				if (str == ":)") exit(0);
				// has to tell the truth
				int asked = -1;
				cout << "? 1 ";
				for (int j = 0; j < 3; j++)
					if (j != i.second) {
						cout << E[j];
						asked = j;
						break;
					}
				cout << '\n';
				fflush(stdout);
				cin >> str;
				if (str == "YES") cout << "! " << E[asked] << '\n';
				else cout << "! " << E[0 ^ 1 ^ 2 ^ i.second ^ asked] << '\n';
				fflush(stdout);
				cin >> str;
				assert(str == ":)");
				exit(0);
			}
		}
		assert(0);
	}
	if (E.size() <= 2) {
		string str;
		for (int i : E) {
			cout << "! " << i << '\n';
			fflush(stdout);
			cin >> str;
			if (str == ":)") exit(0);
		}
		exit(0);
	}
	vector<string> ans;
	int b;
	for (b = 0; (1 << b) < E.size(); b++);
	for (int i = 0; i < b; i++) {
		vector<int> tmp;
		for (int j = 0; j < E.size(); j++)
			if (j & (1 << i))
				tmp.pb(E[j]);
		ans.pb(ask(tmp));
	}
	int idx = 0;
	for (int i = 0; i < b; i++) {
		if (ans[i] == "YES") idx |= (1 << i);
	}
	//~ cout << "CANDIDATE " << idx << endl;
	vector<int> new_E;
	auto remain = brute(idx, b);
	for (int i : remain) {
		if (i >= E.size()) continue;
		new_E.pb(E[i]);
		//~ cout << i << ' ';
	}
	//~ cout << endl;
	recur(new_E);
}

main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		T.pb(i);
	}
	recur(T);
}