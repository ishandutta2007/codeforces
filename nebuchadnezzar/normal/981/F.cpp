#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

int cur_sum, deleted_sum;
vector<tuple<int, int, int>> back, front;

void init() {
	cur_sum = 0;
	deleted_sum = 0;
	back.clear();
	front.clear();
}

int get_min_back() {
	if (szof(back)) {
		return get<2>(back.back());
	}
	return INF;
}

int get_min_front() {
	if (szof(front)) {
		return get<2>(front.back());
	}
	return INF;
}

void add(int val) {
	//cerr << "added " << val << endl;
	cur_sum += val;
	back.push_back({val, cur_sum, min(cur_sum, get_min_back())});
}

void pop() {
	assert(szof(back) || szof(front));
	//cerr << "pop" << endl;
	if (!szof(front)) {
		while (szof(back)) {
			int val, sum, tmp;
			tie(val, sum, tmp) = back.back();
			back.pop_back();
			front.push_back({val, sum, min(sum, get_min_front())});
		}
	}
	deleted_sum += get<0>(front.back());
	front.pop_back();
}

int get_min() {
	return min(get_min_front(), get_min_back()) - deleted_sum;
}

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> boys, girls;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		boys.push_back(num);
		boys.push_back(num + l);
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		girls.push_back(num - l);
		girls.push_back(num);
		girls.push_back(num + l);
	}
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	/*
	for (int num : boys) {
		cerr << num << " ";
	}
	cerr << endl;
	for (int num : girls) {
		cerr << num << " ";
	}
	cerr << endl;
	*/
	int lg = -1, rg = l / 2;
	while (rg - lg > 1) {
		int mid = (lg + rg) / 2;

		//mid = 37;
		//cerr << mid << endl;
		init();
		bool flag = true;

		int c1 = 0, c2 = 0, c3 = 0;
		while (girls[c2] - mid <= boys[c1]) {
			++c2;
		}
		c3 = c2;
		while (c3) {
			if (boys[0] - girls[c3 - 1] <= mid) {
				--c3;
			} else {
				break;
			}
		}

		int c0 = c2;

		//int len = 0;
		//int leng = 0;
		for (int i = 0; i < n; ++i) {
			while (girls[c3] < boys[i] - mid) {
				++c3;
			}
			while (girls[c0] - mid <= boys[i]) {
				++c0;
			}
			c2 = max(c2, c0);
			//cerr << boys[i] << " " << boys[c1] << " " << girls[c2] << " " << girls[c3] << " " << girls[c0] << endl;
			while (true) {
				if (girls[c2] - mid <= boys[c1]) {
					if (c2 == c3 + n) {
						break;
					}
					add(1);
					//++leng;
					++c2;
				} else {
					if (boys[c1] + mid >= boys[i] + l - mid) {
						break;
					}
					add(-1);
					//++len;
					++c1;
				}
			}

			//cerr << i << " " << c1 << " " << c2 << " " << c3 << " " << c0 << endl;
			//cerr << boys[i] << " " << boys[c1] << " " << girls[c2] << " " << girls[c3] << " " << girls[c0] << endl;

			if (c0 - c3 + get_min() < 0) {
				flag = false;
				break;
			}

			if (i == n - 1) {
				break;
			}

			int tmp = deleted_sum;
			pop();
			--tmp;
			assert(tmp == deleted_sum);
			while ((szof(front) || szof(back)) && girls[c0] - mid <= boys[i + 1]) {
				pop();
				++tmp;
				//--leng;
				++c0;
			}
			assert(tmp == deleted_sum);
			//--len;
		}

		if (flag) {
			rg = mid;
		} else {
			lg = mid;
		}
	}

	cout << rg << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}