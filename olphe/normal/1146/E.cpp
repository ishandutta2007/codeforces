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

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

class Add_Segment_Tree {
	vector<long long int>v;
	vector<long long int>add;
	vector<long long int>modi;
	vector<int>l;
	vector<int>r;
	int num;
	long long int ret;
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
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		v[place] = Update(place * 2) + Update(place * 2 + 1);
		return v[place];
	}
	void Modify(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			modi[place] = num * (r[place] - l[place] + 1);
			v[place] = num * (r[place] - l[place] + 1);
			add[place] = 0;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place] / 2;
			v[place * 2] = v[place * 2 + 1] = modi[place] / 2;
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place] / 2;
		add[place * 2 + 1] += add[place] / 2;
		add[place] = 0;
		Modify(a, b, num, place * 2);
		Modify(a, b, num, place * 2 + 1);
		v[place] = v[place * 2] + add[place * 2] + v[place * 2 + 1] + add[place * 2 + 1];
		return;
	}
	void Add(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place] / 2;
					v[place * 2] = v[place * 2 + 1] = modi[place] / 2;
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			add[place] += num * (r[place] - l[place] + 1);
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place] / 2;
			v[place * 2] = v[place * 2 + 1] = modi[place] / 2;
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place] / 2;
		add[place * 2 + 1] += add[place] / 2;
		add[place] = 0;
		Add(a, b, num, place * 2);
		Add(a, b, num, place * 2 + 1);
		v[place] = v[place * 2] + add[place * 2] + v[place * 2 + 1] + add[place * 2 + 1];
		return;
	}
	void Sum(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place] / 2;
					v[place * 2] = v[place * 2 + 1] = modi[place] / 2;
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			ret += v[place] + add[place];
			return;
		}
		if (l[place]>b || r[place]<a) return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place] / 2;
			v[place * 2] = v[place * 2 + 1] = modi[place] / 2;
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place] / 2;
		add[place * 2 + 1] += add[place] / 2;
		add[place] = 0;
		Sum(a, b, place * 2);
		Sum(a, b, place * 2 + 1);
		v[place] = v[place * 2] + add[place * 2] + v[place * 2 + 1] + add[place * 2 + 1];
		return;
	}
public:
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		v.resize(num, 0);
		add.resize(num, 0);
		modi.resize(num, LLONG_MAX);
		Left(1);
		Right(1);
	}
	void Insert(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			v[place] = v[place * 2] + v[place * 2 + 1];
			place /= 2;
		}
	}
	void Modify(int a, int b, long long int num) {
		Modify(a, b, num, 1);
	}
	void Add(int a, int b, long long int num) {
		Add(a, b, num, 1);
	}
	void Init() {
		Update(1);
	}
	long long int Sum(int a, int b) {
		ret = 0;
		Sum(a, b, 1);
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	Add_Segment_Tree asg_p(100001);
	Add_Segment_Tree asg_n(100001);
	asg_p.Modify(1, 100000, -1);
	vector<char>c(M);
	vector<int>q(M);
	for (int i = 0; i < M; i++) {
		cin >> c[i] >> q[i];
		if (c[i] == '>') {
			if (q[i] >= 0) {
				asg_p.Modify(q[i] + 1, 100000, i);
				asg_n.Modify(q[i] + 1, 100000, 0);
			}
			else {
				asg_p.Modify(-q[i], 100000, i);
				asg_n.Modify(-q[i], 100000, 0);
				asg_n.Add(0, -q[i]-1, 1);
			}
		}
		else {
			if (q[i] > 0) {
				asg_p.Modify(q[i], 100000, i);
				asg_n.Modify(q[i], 100000, 0);
				asg_n.Add(0, q[i] - 1, 1);
			}
			else {
				asg_p.Modify(-q[i] + 1, 100000, i);
				asg_n.Modify(-q[i] + 1, 100000, 0);
			}
		}
	}
	unordered_map<int, int>m;
	for (int i = -100000; i <= 100000; i++) {
		if (asg_p.Sum(abs(i), abs(i)) == -1) {
			if (asg_n.Sum(abs(i), abs(i)) & 1)m[i] = -i;
			else m[i] = i;
		}
		else {
			if (c[asg_p.Sum(abs(i),abs(i))] == '>') {
				if (asg_n.Sum(abs(i), abs(i)) & 1)m[i] = abs(i);
				else m[i] = -abs(i);
			}
			else {
				if (asg_n.Sum(abs(i), abs(i)) & 1)m[i] = -abs(i);
				else m[i] = abs(i);
			}
		}
	}
	for (auto &i : v)i = m[i];
	for (auto i : v)cout << i << " ";
	cout << endl;
	return 0;
}