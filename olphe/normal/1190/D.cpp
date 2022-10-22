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
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>>v(N);
	for (auto &i : v) {
		cin >> i.second >> i.first;
		i.first *= -1;
	}
	sort(v.begin(), v.end());
	map<int, int>m;
	for (auto i : v)m[i.first] = 0;
	int cnt = 0;
	for (auto &i : m)i.second = cnt++;
	vector<vector<int>>w(m.size());
	for (auto i : v) {
		w[m[i.first]].push_back(i.second);
	}
	map<int, int>mm;
	for (auto i : w) {
		for (auto j : i)mm[j] = 0;
	}
	cnt = 0;
	for (auto &i : mm) {
		i.second = cnt++;
	}
	set<int>s;
	int num[200001] = {};
	Add_Segment_Tree asg(200000);
	for (int i = 0; i < m.size(); i++) {
		for (auto j : w[i]) {
			if (s.find(j) == s.end())asg.Add(mm[j], 1, true);
			s.insert(j);
		}
		num[s.size()]++;
		num[asg.Sum(0, mm[w[i][0]])-1]--;
		for (int j = 1; j < w[i].size(); j++) {
			num[asg.Sum(0, mm[w[i][j]]) - asg.Sum(0, mm[w[i][j - 1]]) - 1]--;
		}
		num[s.size() - asg.Sum(0, mm[w[i].back()])]--;

	}
	long long int ans = 0;
	for (long long int i = 1; i <= 200000; i++) {
		ans += i * (i + 1) / 2 * num[i];
	}
	cout << ans << endl;
}