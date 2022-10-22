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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

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
			v.resize(num, LLONG_MAX);
		}
		else v.resize(num, LLONG_MIN);
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

	cin >> N >> M;
	vector<int>v(N);
	int box = 0;
	bool largest = false;
	bool zero = false;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] == M) {
			largest = true;
		}
		if (!v[i]) {
			zero = true;
		}
		box |= v[i];
	}
	if (!largest && !zero) {
		cout << "NO\n";
		return 0;
	}
	if (!box) {
		cout << "YES\n";
		for (int i = 0; i < N; i++) {
			cout << M << " ";
		}
		cout << endl;
		return 0;
	}
	vector<int>l(v);
	vector<int>r(v);
	if (!l[0] && !largest) {
		l[0] = M;
		largest = true;
	}
	for (int i = 1; i < N; i++) {
		if (!l[i]) {
			if (!largest) {
				l[i] = M;
				largest = true;
				continue;
			}
			l[i] = l[i - 1];
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		if (!r[i]) {
			r[i] = r[i + 1];
		}
	}
	for (int i = 0; i < N; i++) {
		v[i] = max(l[i], r[i]);
	}
	vector<int>lft(M + 1, N - 1);
	vector<int>rht(M + 1, 0);
	for (int i = 0; i < N; i++) {
		lft[v[i]] = min(lft[v[i]], i);
		rht[v[i]] = max(rht[v[i]], i);
	}
	Segment_Tree sg(N, true);
	for (int i = 0; i < N; i++) {
		sg.Insert(i, v[i], false);
	}
	sg.TopDown();
	for (int i = 1; i <= M; i++) {
		if (lft[i] >= rht[i])continue;
		int box = sg.RMQ(lft[i], rht[i]);
		if (box < i) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (auto i : v)cout << i << " ";
	cout << endl;
	return 0;
}