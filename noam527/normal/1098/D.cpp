#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

struct fenwick {
	int n;
	vector<ll> tree;
	fenwick() {}
	fenwick(int sz) {
		n = sz;
		tree.resize(n + 1, 0);
	}
	void upd(int pos, ll add) {
		for (; pos <= n; pos += (pos & -pos)) tree[pos] += add;
	}
	ll query(int pos) {
		ll rtn = 0;
		for (; pos; pos -= (pos & -pos)) rtn += tree[pos];
		return rtn;
	}
};

int q;
vector<pair<int, int>> a;
map<int, int> to, ba;
fenwick F;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> q;
	char ch;
	a.resize(q);
	for (int i = 0; i < q; i++) {
		cin >> ch >> a[i].second;
		if (ch == '-') a[i].first = -1;
		else a[i].first = 1;
	}
	int nxt = 1;
	for (auto &i : a) to[i.second] = 0;
	for (auto &i : to) i.second = nxt++;
	for (auto &i : to) ba[i.second] = i.first;

	F = fenwick(nxt + 10);
	int nxtind = 0;
	set<pair<ll, int>> val;
	for (auto &i : a) {
		if (i.first == 1) {
			val.insert({ i.second, nxt });
			nxt++;
			F.upd(to[i.second], i.second);
		}
		else {
			val.erase(val.lower_bound({ i.second, -1 }));
			F.upd(to[i.second], -i.second);
		}
		if (val.size()) {
			int cnt = 0;
			auto it = val.begin(), it2 = it;
			ll cursum = it->first;
//			cout << "cursum " << cursum << '\n';
//			for (const auto &x : val) cout << x.first << " "; cout << '\n';
			while (it != val.end()) {
				it2 = val.upper_bound({ 2 * cursum, -1 });
				if (it2 != val.end()) {
					ll ss = F.query(to[it2->first] - 1);
					if (2 * ss < it2->first) cnt++;
					it = it2;
					cursum = ss + it2->first;
				}
				else {
					it = val.end();
				}
			}
			cout << (int)val.size() - 1 - cnt << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}