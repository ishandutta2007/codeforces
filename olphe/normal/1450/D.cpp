#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class Segment_Tree {
	vector<long long int>v;
	int num;
	long long int ret;
	bool is_min;
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		if (is_min) {
			v[place] = min(Update(place * 2), Update(place * 2 + 1));
			return v[place];
		}
		v[place] = max(Update(place * 2), Update(place * 2 + 1));
		return v[place];
	}
public:
	Segment_Tree(int n, bool min) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		is_min = min;
		if (min) {
			v.resize(num, MOD*MOD);
		}
		else v.resize(num, -MOD * MOD);
	}
	void Insert(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			if (is_min)v[place] = min(v[place * 2], v[place * 2 + 1]);
			else v[place] = max(v[place * 2], v[place * 2 + 1]);
			place /= 2;
		}
	}
	void TopDown() {
		Update(1);
	}
	long long int RMQ(int a, int b) {
		if (is_min)ret = LLONG_MAX;
		else ret = LLONG_MIN;
		if (is_min) {
			b++;
			for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
				if (a & 1)ret = min(ret, v[a++]);
				if (b & 1)ret = min(ret, v[--b]);
			}
		}
		else {
			b++;
			for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
				if (a & 1)ret = max(ret, v[a++]);
				if (b & 1)ret = max(ret, v[--b]);
			}
		}
		return ret;
	}
};

void Solve() {
	cin >> N;
	vector<pair<int,int>>vp(N);
	for (int i = 0; i < N; i++) {
		cin >> vp[i].first;
		vp[i].second = i;
	}
	sort(vp.begin(), vp.end());
	set<int>s;
	s.insert(-1);
	s.insert(N);
	vector<int>ed(N + 1);
	for (auto i : vp) {
		auto it = s.lower_bound(i.second);
		auto pv = prev(it);
		ed[i.first] = max(ed[i.first], *it - *pv - 1);
		s.insert(i.second);
	}
	Segment_Tree msg(N + 1, true);
	Segment_Tree Msg(N + 1, false);
	for (int i = 1; i <= N; i++) {
		msg.Insert(i, ed[i], false);
		Msg.Insert(i, ed[i], false);
	}
	msg.TopDown();
	Msg.TopDown();
	for (int i = N; i > 0; i--) {
		if (msg.RMQ(1, i) < N - i + 1 || Msg.RMQ(i + 1, N) >= N - i + 1)cout << 0;
		else cout << 1;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}