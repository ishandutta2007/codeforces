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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

constexpr int BOX = 316;

struct Query {
	int l, r, idx;
	bool operator<(const Query& q) const{
		return make_pair(l / BOX, r) < make_pair(q.l / BOX, q.r);
	}
};

class Add_Segment_Tree {
	vector<vector<int>>v;
	vector<int> ret;
	int num;
	vector<int> Merge(vector<int>y, vector<int>z) {
		int a = 0, b = 0;
		vector<int>x;
		while (x.size() < 31) {
			if (a == y.size() && b == z.size()) {
				break;
			}
			else if (a == y.size()) {
				x.push_back(z[b++]);
			}
			else if (b == z.size()) {
				x.push_back(y[a++]);
			}
			else if (y[a] < z[b]) {
				x.push_back(y[a++]);
			}
			else {
				x.push_back(z[b++]);
			}
		}
		return x;
	}
public:
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		v.resize(num);
	}
	void Add(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place].push_back(num);
	}
	void Topdown() {
		for (int i = v.size() / 2 - 1; i > 0; i--) {
			v[i] = Merge(v[i * 2], v[i * 2 + 1]);
		}
	}
	vector<int> Sum(int a, int b) {
		ret.clear();
		b++;
		for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				ret = Merge(ret, v[a]);
				a++;
			}
			if (b & 1) {
				--b;
				ret = Merge(ret, v[b]);
			}
		}
		return ret;
	}
};

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	Add_Segment_Tree asg(N);
	for (int i = 0; i < N; i++) {
		asg.Add(i, v[i], false);
	}
	asg.Topdown();
	cin >> M;
	vector<Query>query(M);
	for (int i = 0; i < M; i++) {
		cin >> query[i].l >> query[i].r;
		query[i].l--;
		query[i].idx = i;
	}
	sort(query.begin(), query.end());
	L = 0, R = 0;
	multiset<int>ms;
	vector<int>ret(M);
	for (auto q : query) {
		auto w = asg.Sum(q.l, q.r - 1);
		int ans = 0;
		ans = INT_MAX;
		for (int i = 0; i < w.size(); i++) {
			for (int j = i + 1; j < w.size(); j++) {
				ans = min(ans, w[i] | w[j]);
			}
		}
		ret[q.idx] = ans;
	}
	for (auto i : ret)cout << i << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}