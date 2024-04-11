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
		if (is_min)ret = INT_MAX;
		else ret = -10;
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

	cin >> N >> M;
	vector<int>ax(N);
	vector<int>ay(N);
	vector<int>bx(M);
	vector<int>by(M);
	map<int, int>xp;
	map<int, int>yp;
	for (int i = 0; i < N; i++) {
		cin >> ax[i] >> ay[i];
		xp[ax[i]] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> bx[i] >> by[i];
		xp[bx[i]] = 0;
		xp[bx[i] + 1] = 0;
	}
	xp[-1] = yp[-1] = 0;
	for (auto &i : xp)i.second = W++;
	for (auto &i : yp)i.second = H++;
	Segment_Tree sg(xp.size(), false);
	for (int i = 0; i < M; i++) {
		if (sg.RMQ(xp[bx[i]], xp[bx[i]]) < by[i]) {
			sg.Insert(xp[bx[i]], by[i], true);
		}
	}
	vector<int>ans(1000001, -MOD);
	for (int i = 0; i < N; i++) {
		ans[0] = max(ans[0], (int)sg.RMQ(xp[ax[i]], W) - ay[i] + 1);
		for (int j = 0; j < M; j++) {
			if (bx[j] < ax[i])continue;
			ans[bx[j] - ax[i]] = max(ans[bx[j] - ax[i]], max(0,(int)sg.RMQ(xp[bx[j]], W) - ay[i] + 1));
			ans[bx[j] - ax[i] + 1] = max(ans[bx[j] - ax[i] + 1], max(0, (int)sg.RMQ(xp[bx[j] + 1], W) - ay[i] + 1));
		}
	}
	int ret = MOD;
	for (int i = 1000000; i >= 0; i--) {
		if (i < 1000000)ans[i] = max(ans[i], ans[i + 1]);
		if (ans[i] == -MOD)continue;
		ret = min(ret, ans[i] + i);
	}
	ret = max(ret, 0);
	cout << ret << endl;
}