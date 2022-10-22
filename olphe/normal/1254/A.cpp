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
#include "functional"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

class Add_Segment_Tree {
	vector<long double >v;
	vector<int>l;
	vector<int>r;
	long double  ret;
	int num;
	long double  Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		v[place] = Update(place * 2) + Update(place * 2 + 1);
		return v[place];
	}
	void Sum(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			ret += v[place];
			return;
		}
		if (l[place] > b || r[place] < a) return;
		Sum(a, b, place * 2);
		Sum(a, b, place * 2 + 1);
		return;
	}
public:
	void Left(int place) {
		if (place >= v.size() / 2) {
			l[place] = place - v.size() / 2;
			return;
		}
		Left(place * 2);
		Left(place * 2 + 1);
		l[place] = l[place * 2];
		return;
	}
	void Right(int place) {
		if (place >= v.size() / 2) {
			r[place] = place - v.size() / 2;
			return;
		}
		Right(place * 2);
		Right(place * 2 + 1);
		r[place] = r[place * 2 + 1];
		return;
	}
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		l.resize(num);
		r.resize(num);
		v.resize(num, 0);
		Left(1);
		Right(1);
	}
	void Add(int place, long double  num, bool update) {
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
	long double  Sum(int a, int b) {
		ret = 0;
		Sum(a, b, 1);
		return ret;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> H >> W >> N;
		vector<string>s(H);
		for (auto &i : s)cin >> i;
		vector<vector<int>>ans(H, vector<int>(W));
		int cnt = 0;
		int rice = 0;
		for (auto i : s)for (auto j : i)rice += j == 'R';
		vector<int>num(N);
		for (int i = 0; i < rice; i++)num[i%N]++;
		int y = 0, x = 0;
		for (int i = 0; i < N; i++) {
			while (num[i] || (y < H&&i == N - 1)) {
				if (s[y][x] == 'R') {
					num[i]--;
				}
				ans[y][x] = i;
				if (y & 1) {
					if (x)x--;
					else y++;
				}
				else {
					if (x + 1 < W)x++;
					else y++;
				}
			}
		}
		vector<string>ret(H, string(W, '0'));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (ans[i][j] < 10)ret[i][j] = char(ans[i][j] + '0');
				else if (ans[i][j] < 36)ret[i][j] = char('A' + ans[i][j] - 10);
				else ret[i][j] = char('a' + ans[i][j] - 36);
			}
		}
		for (auto i : ret)cout << i << endl;
	}
	return 0;
}