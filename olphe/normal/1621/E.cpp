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

struct Group {
	long long c, p;
	int idx, sum;
	bool operator<(const Group& g)const {
		return c * g.p < p* g.c;
	}
	bool operator<=(const Group& g)const {
		return c * g.p <= p* g.c;
	}
};

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
			v.resize(num, MOD * MOD);
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
		ret = 1;
		b++;
		for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
			if (a & 1)ret = min(ret, v[a++]);
			if (b & 1)ret = min(ret, v[--b]);
		}
		return ret;
	}
};

vector<int> func(vector<long long>v, vector<vector<long long>>w,vector<Group>group) {
	vector<int>ret;
	int p = 0;
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j < w[i].size(); j++) {
			auto g = group;
			g[i].c -= w[i][j];
			g[i].p--;
			sort(g.begin(), g.end());
			int ans = 1;
			for (int k = 0; k < M; k++) {
				Group vk;
				vk.p = 1;
				vk.c = v[k];
				if (vk < g[k]) {
					ans = 0;
				}
			}
			ret.push_back(ans);
		}
	}
	return ret;
}

class XorShift {
	unsigned int x, y, z, w, t;
public:
	XorShift() {
		x = 133553533;
		y = 314867339;
		z = 664298413;
		w = 999999937;
		t = 0;
	}
	unsigned int rand() {
		t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		return w & 0x7fffffff;
	}
};
XorShift xs;

void Solve() {
	cin >> N >> M;
	//M = xs.rand() % 100 + 1, N = M + xs.rand() % 100;
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	//for (auto& i : v)i = xs.rand() % 50000 + 1;

	vector<vector<long long>>w(M);
	vector<Group>group;
	int sum = 0;
	for (auto& i : w) {
		cin >> K;
		//K = xs.rand() % 100000 + 2;
		i.resize(K);
		for (auto& j : i)cin >> j;
		//for (auto& j : i)j = xs.rand() % 50000 + 1;
		Group g;
		g.c = accumulate(i.begin(), i.end(), 0LL);
		g.p = K;
		g.idx = group.size();
		g.sum = sum;
		sum += K;
		group.push_back(g);
	}
	vector<int>ans(sum);
	sort(v.rbegin(), v.rend());
	v.resize(M);
	reverse(v.begin(), v.end());
	//auto ans2=func(v, w,group);
	sort(group.begin(), group.end());
	Segment_Tree sg(M, true);
	Segment_Tree sg_plus(M, true);
	Segment_Tree sg_minus(M, true);
	for (int i = 0; i < M; i++) {
		Group g;
		g.c = v[i];
		g.p = 1;
		if (group[i] <= g) {
			sg.Insert(i, 1, true);
		}
		else {
			sg.Insert(i, 0, true);
		}
		if (i) {
			if (group[i - 1] <= g) {
				sg_plus.Insert(i - 1, 1, true);
			}
			else {
				sg_plus.Insert(i - 1, 0, true);
			}
		}
		if (i + 1 < M) {
			if (group[i + 1] <= g) {
				sg_minus.Insert(i + 1, 1, true);
			}
			else {
				sg_minus.Insert(i + 1, 0, true);
			}
		}
	}
	int p = 0;
	for (auto i : group) {
		int idx = i.sum;
		for (auto j : w[i.idx]) {
			auto g = i;
			g.c -= j;
			g.p--;
			int cans = 1;
			auto it = lower_bound(group.begin(), group.end(), g) - group.begin();
			//cout << i.c << " " << i.p << " --" << endl;
			//cout << p << " --- " << it << endl;
			if (it == p) {
				cans = min(cans, (int)sg.RMQ(0, p - 1));
				cans = min(cans, (int)sg.RMQ(p + 1, M - 1));
				Group vit;
				vit.c = v[it];
				vit.p = 1;
				if (vit < g) {
					cans = 0;
				}
			}
			else if (it > p) {
				it--;
				cans = min(cans, (int)sg.RMQ(0, p - 1));
				cans = min(cans, (int)sg.RMQ(it + 1, M - 1));
				cans = min(cans, (int)sg_minus.RMQ(p + 1, it));
				Group vit;
				vit.c = v[it];
				vit.p = 1;
				if (vit < g) {
					cans = 0;
				}
			}
			else {
				cans = min(cans, (int)sg.RMQ(0, it - 1));
				cans = min(cans, (int)sg.RMQ(p + 1, M - 1));
				cans = min(cans, (int)sg_plus.RMQ(it, p - 1));
				Group vit;
				vit.c = v[it];
				vit.p = 1;
				if (vit < g) {
					cans = 0;
				}
			}
			//cout << "idx " << idx << endl;
			ans[idx] = cans;
			idx++;
		}
		p++;
	}
	/*
	if (0) {
		for (auto i : v)cout << i << " ";
		cout << endl << endl;
		for (auto i : w) {
			for (auto j : i)cout << j << " ";
			cout << endl;
		}
		for (auto i : ans)cout << i;
		cout << endl;
		for (auto i : ans2)cout << i;
		cout << endl;
	}
	*/

	for (auto i : ans)cout << i;
	cout << endl;
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