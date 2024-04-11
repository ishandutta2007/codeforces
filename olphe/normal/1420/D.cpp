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
constexpr double EPS = 1e-5;

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

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<pair<int, int>>v(N);
	map<int, int>mp;
	vector<long long int>by(N + 1, 1);
	vector<long long int>rev(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i%MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	for (auto &i : v) {
		cin >> i.first >> i.second;
		mp[i.first] = mp[i.second] = 0;
	}
	int cnt = 0;
	for (auto &i : mp)i.second = cnt++;
	for (auto &i : v) {
		i.first = mp[i.first];
		i.second = mp[i.second];
	}
	sort(v.begin(), v.end());
	Add_Segment_Tree asg(cnt);
	long long int ans = 0;
	for (auto i : v) {
		int num = asg.Sum(i.first, cnt);
		if (num >= K - 1) {
			ans += by[num] * rev[K - 1] % MOD* rev[num - K + 1];
			ans %= MOD;
		}
		asg.Add(i.second, 1, true);
	}
	cout << ans << endl;
}