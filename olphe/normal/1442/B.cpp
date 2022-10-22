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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class Add_Segment_Tree {
	vector<long long int>v;
	long long int ret;
	int num;
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		v[place] = Update(place * 2) + Update(place * 2 + 1);
		return v[place];
	}
public:
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		v.resize(num, 0);
	}
	void Add(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] += num;
		if (!update)return;
		place /= 2;
		while (place) {
			v[place] = v[place * 2] + v[place * 2 + 1];
			place /= 2;
		}
	}
	void TopDown() {
		Update(1);
	}
	long long int Sum(int a, int b) {
		ret = 0;
		b++;
		for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
			if (a & 1)ret += v[a++];
			if (b & 1)ret += v[--b];
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int>v(N);
		vector<int>w(K);
		vector<int>place(N + 1);
		for (auto &i : v)cin >> i;
		for (int i = 0; i < N; i++) {
			place[v[i]] = i;
		}
		set<int>st;
		for (auto &i : w)cin >> i;
		reverse(w.begin(), w.end());
		vector<int>l(K);
		vector<int>r(K);
		Add_Segment_Tree asg(N + 1);
		for (auto i : w) {
			asg.Add(place[i], 1, false);
		}
		st.insert(-1);
		st.insert(N);
		asg.TopDown();
		long long int ans = 1;
		for (auto i : w) {
			auto it = st.lower_bound(place[i]);
			auto pv = prev(it);
			int nx = *it - place[i];
			nx -= asg.Sum(place[i], *it - 1);
			int bf = place[i] - *pv;
			bf -= asg.Sum(*pv + 1, place[i]);
			asg.Add(place[i], -1, true);
			st.insert(place[i]);
		//	cout << nx << " " << bf << endl;
			if (nx > 0 && bf > 0)ans *= 2;
			else if (nx == 0 && bf == 0)ans = 0;
			ans %= MOD;
		}
		cout << ans % MOD << endl;
	}
}