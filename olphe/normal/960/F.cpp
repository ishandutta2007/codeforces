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
		if (l[place] >= a&&r[place] <= b) {
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
		else v.resize(num, 0);
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

struct Edge {
	long long int a, b, c;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<set<int>>vs(N + 1);
	vector<vector<pair<int, int>>>edge(N + 1);
	vector < Edge>ve;
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		ve.push_back({ L,R,K });
		edge[L].push_back({ R,K });
		vs[R].insert(K);
	}
	vector<int>sum(N + 1);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + vs[i].size();
	}
	vector<vector<int>>v(N + 1);
	for (int i = 1; i <= N; i++) {
		for (auto j : vs[i]) {
			v[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++) {
		v[i].push_back(MOD);
	}
	Segment_Tree sg(sum[N], false);
	for (auto i : ve) {
		L = -1;
		R = v[i.a].size() - 1;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (v[i.a][mid] >= i.c) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		int l = -1;
		int r = v[i.b].size() - 1;
		while (r - l > 1) {
			int mid = (l + r + 1) / 2;
			if (v[i.b][mid] >= i.c) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (R == 0) {
			sg.Insert(sum[i.b - 1] + r, 1, true);
		}
		else {
			sg.Insert(sum[i.b - 1] + r, sg.RMQ(sum[i.a - 1], sum[i.a - 1] + R - 1) + 1, true);
		}
	}
	cout << sg.RMQ(0, sum[N]) << endl;
	return 0;
}