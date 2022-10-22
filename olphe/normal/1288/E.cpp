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
constexpr long double EPS = 1e-12;

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

struct Query {
	int l, r, index;
	Query(const int ll, const int rr, const int ii) {
		l = ll, r = rr, index = ii;
		return;
	}
	bool operator<(const Query&q)const {
		return r < q.r;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v;
	for (int i = N - 1; i >= 0; i--)v.push_back(i);
	for (int i = 0; i < M; i++) {
		cin >> K;
		K--;
		v.push_back(K);
	}
	vector<vector<int>>p(N);
	for (int i = 0; i < v.size(); i++) {
		p[v[i]].push_back(i);
	}
	for (int i = 0; i < N; i++)p[i].push_back(v.size());
	vector<int>l(N);
	vector<int>r(N);
	for (int i = 0; i < N; i++)r[i] = i;
	vector<Query>query;
	for (int i = 0; i < N; i++) {
		if (p[i].size() > 2)l[i] = 0;
		else l[i] = i;
		for (int j = 1; j < p[i].size(); j++) {
			if (p[i][j - 1] + 1 == p[i][j])continue;
			query.push_back(Query(p[i][j - 1] + 1, p[i][j] - 1, i));
		}
	}
	sort(query.begin(), query.end());
	Add_Segment_Tree asg(v.size() + 1);
	vector<int>last(N);
	for (int i = 0; i < N; i++) {
		last[i] = N - i - 1;
		asg.Add(i, 1, false);
	}
	asg.TopDown();
	R = N;
	for (auto i : query) {
		while (R <= i.r) {
			asg.Add(last[v[R]], -1, true);
			last[v[R]] = R;
			asg.Add(R, 1, true);
			R++;

		}
		r[i.index] = max(r[i.index], (int)asg.Sum(i.l, i.r));
	}
	for (int i = 0; i < N; i++) {
		cout << l[i] + 1 << " " << r[i] + 1 << "\n";
	}
	return 0;
}