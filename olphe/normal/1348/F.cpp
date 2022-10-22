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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	bool flag = true;
	vector<pair<int, int>>w(N + 1);
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> L >> R;
		v[L].push_back({ R,i });
		w[i] = { L,R };
	}
	set<pair<int, int>>st;
	vector<int>ans(N + 1);
	for (int i = 1; i <= N; i++) {
		for (auto j : v[i]) {
			st.insert(j);
		}
		ans[i] = st.begin()->second;
		st.erase(st.begin());
	}
	Segment_Tree l(N + 1, true);
	for (int i = 1; i <= N; i++) {
		int id = ans[i];
		l.Insert(i, w[id].first*MOD+i, false);
	}
	l.TopDown();
	int a = -1, b = -1;
	for (int i = 1; i <= N; i++) {
		int id = ans[i];
		R = w[id].second;
		auto box = l.RMQ(i + 1, R);
		if (box / MOD > i)continue;
		a = i, b = box % MOD;
	}
	if (a == -1) {
		cout << "YES\n";
		vector<int>ret(N + 1);
		for (int i = 1; i <= N; i++) {
			ret[ans[i]] = i;
		}
		for (int i = 1; i <= N; i++)cout << ret[i] << " ";
		cout << endl;
	}
	else {
		cout << "NO\n";
		vector<int>ret(N + 1);
		for (int i = 1; i <= N; i++) {
			ret[ans[i]] = i;
		}
		for (int i = 1; i <= N; i++)cout << ret[i] << " ";
		cout << endl;
		swap(ans[a], ans[b]);
		for (int i = 1; i <= N; i++) {
			ret[ans[i]] = i;
		}
		for (int i = 1; i <= N; i++)cout << ret[i] << " ";
		cout << endl;
	}
}