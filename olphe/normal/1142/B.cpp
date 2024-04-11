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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

class Segment_Tree {
	vector<long long int>v;
	vector<int>l;
	vector<int>r;
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
	void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (is_min)ret = min(ret, v[place]);
			else ret = max(ret, v[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		RMQ(a, b, place * 2);
		RMQ(a, b, place * 2 + 1);
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
	Segment_Tree(int n, bool min) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		is_min = min;
		if (min) {
			v.resize(num, MOD*MOD);
		}
		else v.resize(num, -MOD * MOD);
		Left(1);
		Right(1);
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
		RMQ(a, b, 1);
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>p(N);
	for (auto &i : p)cin >> i;
	vector<int>place(N + 1);
	for (int i = 0; i < N; i++) {
		place[p[i]] = i;
	}
	vector<int>v(M);
	for (auto &i : v)cin >> i;

	vector<int>left(N + 1, -1);
	vector<vector<int>>d(20, vector<int>(M, -1));
	for (int i = M - 1; i >= 0; i--) {
		left[v[i]] = i;
		if (left[p[(place[v[i]] + 1) % N]] == -1)continue;
		d[0][i] = left[p[(place[v[i]] + 1) % N]];
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < M; j++) {
			if (d[i - 1][j] == -1)continue;
			d[i][j] = d[i - 1][d[i - 1][j]];
		}
	}
	Segment_Tree sg(M, true);
	for (int i = 0; i < M; i++) {
		int cn = i;
		for (int j = 0; j < 20; j++) {
			if (((N - 1) >> j) & 1) {
				cn = d[j][cn];
			}
			if (cn == -1)	break;
		}
		if (cn != -1) {
			sg.Insert(i, cn, true);
		}
	//	cout << i << " " << cn << endl;
	}
	//for (int i = 0; i < M; i++)cout << i << " " << rg[i] << endl;
	string ans;
	for (int i = 0; i < K; i++) {
		cin >> L >> R;
		L--;
		R--;
		long long int box = sg.RMQ(L, M);
		if (box > R)ans.push_back('0');
		else ans.push_back('1');
	}
	cout << ans << endl;
	return 0;
}