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
constexpr double EPS = 1e-8;

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

	cin >> K;
	while (K--) {
		cin >> N;
		vector<pair<int, int>>v(N);
		for (auto &i : v) {
			cin >> i.first >> i.second;
			i.first *= 2, i.second *= 2;
		}
		sort(v.begin(), v.end());
		vector<int>flag(N);
		R = -MOD*2;
		for (int i = 0; i < N; i++) {
			if (i + 1 == N) {
				if (R < v[i].first)flag[i] = 1;
			}
			else {
				if (R < v[i].first&&v[i].second < v[i + 1].first)flag[i] = 1;
			}
		}
		map<int, int>mp;
		for (auto i : v)mp[i.first] = mp[i.second] = mp[i.second + 1] = 0;
		int cnt = 0;
		for (auto &i : mp)i.second = cnt++;
		for (auto &i : v)i.first = mp[i.first], i.second = mp[i.second];
		vector<int>sum(mp.size() + 1);
		for (auto i : v) {
			sum[i.first]++;
			sum[i.second + 1]--;
		}
		for (int i = 1; i <= mp.size(); i++)sum[i] += sum[i - 1];
		set<int>st;
		set<int>rev_st;
		for (int i = 0; i <= mp.size(); i++) {
			if (sum[i] > 1) {
				st.insert(i);
				rev_st.insert(-i);
			}
		}
		int fst = 1;
		long long int ans = 1;
		for (int i = 1; i < mp.size(); i++) {
			if (sum[i] == 0 && sum[i - 1] > 0 && sum[i + 1] > 0)fst++;
		}
		Add_Segment_Tree asg(mp.size() + 1);
		for (int i = 1; i <= mp.size(); i++) {
			if (sum[i] == 1 && sum[i - 1] > 1)asg.Add(i, 1, false);
		}
		asg.TopDown();
		for (int i = 0; i < N; i++) {
			if (flag[i]) {
				ans = max(ans, fst - 1LL);
				continue;
			}
			L = *st.lower_bound(v[i].first);
			R = -*rev_st.lower_bound(-v[i].second);
			ans = max(ans, fst + asg.Sum(L, R));
		}
		cout << ans << endl;
	}
}