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
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

class Add_Segment_Tree {
	vector<long long int>v;
	vector<int>l;
	vector<int>r;
	long long int ret;
	int num;
	long long int Update(int place) {
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
		Sum(a, b, 1);
		return ret;
	}
};

struct Query {
	long long int l, d, r, u,index;
	long long int ld, lu, rd, ru;
	void out() {
		l--;
		d--;
		u = N - u;
		r = N - r;
		l *= l - 1;
		r *= r - 1;
		d *= d - 1;
		u *= u - 1;
		ld *= ld - 1;
		lu *= lu - 1;
		rd *= rd - 1;
		ru *= ru - 1;
		cout << (N*(N - 1) - l - d - u - r + ld + lu + rd + ru) / 2 << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<Query>>query(N + 1);
	vector<Query>w(K);
	for (int i = 0; i < K; i++) {
		cin >> w[i].l >> w[i].d >> w[i].r >> w[i].u;
		w[i].index=i;
		query[w[i].l-1].push_back(w[i]);
		query[w[i].r].push_back(w[i]);
	}
	Add_Segment_Tree asg(N+1);
	for (int i = 0; i < N; i++) {
		for (auto j : query[i]) {
			if (i == j.l-1) {
				w[j.index].ld = asg.Sum(1, j.d - 1);
				w[j.index].lu = asg.Sum(j.u + 1, N);
			}
			else {
				w[j.index].rd = j.d - 1 - asg.Sum(1, j.d - 1);
				w[j.index].ru = N - j.u - asg.Sum(j.u + 1, N);
			}
		}
		asg.Add(v[i], 1, true);
	}
	for (auto &i : w) {
//		cout << i.l << " " << i.r << " " << i.d << " " << i.u << " " << i.ld << " " << i.lu << " " << i.rd << " " << i.ru << endl;
		i.out();
	}
	return 0;
}