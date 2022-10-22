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

long long int inv(vector<pair<int, int>>v,int num) {
	Add_Segment_Tree asg(N);
	for (auto &i : v)i.first ^= num;
	sort(v.begin(), v.end());
	long long int ret = 0;
	for (auto i : v) {
		ret += asg.Sum(i.second + 1, N - 1);
		asg.Add(i.second, 1, true);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>>v(N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	long long int bef = inv(v, 0);
	for (int i = 29; i >= 0; i--) {
		auto box = inv(v, 1 << i);
		if (box < bef) {
			for (auto &j : v)j.first ^= 1 << i;
			sort(v.begin(), v.end());
			bef = box;
			ans ^= 1 << i;
		}
	}
	cout << bef << " " << ans << endl;
}