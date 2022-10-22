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

void Solve() {
	cin >> N;
	string s, t;
	cin >> s >> t;
	//s = string(N-2, 'b');
	//s.push_back('c');
	//s.push_back('a');
	//t = string(N, 'b');
	if (s < t) {
		cout << 0 << endl;
		return;
	}
	Add_Segment_Tree asg(N);
	for (int i = 0; i < N; i++) {
		asg.Add(i, 1, true);
	}
	auto u = s;
	sort(u.begin(), u.end());
	if (u >= t) {
		cout << -1 << endl;
		return;
	}
	vector<vector<int>>place(26);
	for (int i = 0; i < N; i++) {
		place[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++) {
		place[i].push_back(1e13);
		reverse(place[i].begin(), place[i].end());
	}
	long long ans = LLONG_MAX;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < t[i] - 'a'; j++) {
			if (place[j].back() > N)continue;
			int p = asg.Sum(0, place[j].back() - 1) + i;
			ans = min(ans, sum + p - i);
		}
		if (place[t[i] - 'a'].back() > N)break;
		int p = asg.Sum(0, place[t[i] - 'a'].back() - 1) + i;
		sum += p - i;
		asg.Add(place[t[i] - 'a'].back(), -1, true);
		place[t[i] - 'a'].pop_back();
		if (sum >= ans)break;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}