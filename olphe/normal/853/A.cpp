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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, L, R, H, W;

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
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		if (min) {
			v.resize(num, LLONG_MAX);
			is_min = true;
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
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	scanf("%lld %lld", &N, &K);
	vector<long long int> cost(N+1);
	vector<long long int> ans(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &cost[i]);
		cost[i] = cost[i] * MOD + i;
	}
	sort(cost.begin(), cost.end());
	reverse(cost.begin(), cost.end());
	Segment_Tree sg(N+1, true);
	for (int i = 1; i <= N; i++) {
		sg.Insert(i, i, false);
	}
	sg.TopDown();
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		long long int box = sg.RMQ(max((long long int)1, cost[i] % MOD - K), N);
		sum += (box + K - cost[i] % MOD)*(cost[i] / MOD);
		ans[cost[i] % MOD] = box + K;
		sg.Insert(box, INT_MAX, true);
	}
	cout << sum << endl;
	for (int i = 1; i <= N; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%lld", ans[i]);
	}
	printf("\n");
	return 0;
}