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

	cin >> N >> T;
	vector<int>v(N);
	for (auto &i : v) {
		cin >> i;
		i--;
	}
	Add_Segment_Tree asg(N);
	asg.Add(0, N, true);
	vector<int>border(N);
	for (int i = 0; i < N; i++) {
		if (v[i] > i) {
			border[i] = 0;
			continue;
		}
		if (v[i] == i) {
			asg.Add(i + 1, 1, true);
			border[i] = i + 1;
			continue;
		}
		L = 0, R = N + 1;
		while (R - L > 1) {
			int mid = (L + R) / 2;
			if (asg.Sum(mid, N) >= i - v[i])L = mid;
			else R = mid;
		}
		border[i] = L;
		asg.Add(L, 1, true);
	}
	Add_Segment_Tree sg(N);
	vector<vector<int>>box(N+1);
	for (int i = 0; i < N; i++) {
		box[border[i]].push_back(i);
	}
	vector<pair<pair<int, int>,int>>query(T);
	int cnt = 0;
	for (auto &i : query) {
		cin >> i.first.first >> i.first.second;
		i.second = cnt++;
	}
	vector<int>ans(T);
	sort(query.rbegin(), query.rend());
	int bef = N;
	for (auto i : query) {
		while (i.first.first < bef) {
			for (auto j : box[bef]) {
				sg.Add(j, 1, true);
			}
			bef--;
		}
		ans[i.second] = sg.Sum(i.first.first, N - i.first.second - 1);
	}
	for (auto i : ans)cout << i << endl;
}