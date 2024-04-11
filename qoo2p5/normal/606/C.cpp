#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;

int n;
int p[200000];
int dp[200000];
int from[200000];

struct segment {
	int a, b;
	int id;

	segment() {}

	segment(int a, int b, int id) : a(a), b(b), id(id) {}

	bool operator<(const segment &other) const {
		return a < other.a;
	}
};

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	vector<segment> segs;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 < n && p[j + 1] - p[j] == 1) {
			j++;
		}

		segs.pb(segment(p[i], p[j], sz(segs)));

		i = j;
	}

	set<segment> q;
	for (segment &s : segs) {
		auto it = q.lower_bound(s);
		if (sz(q) == 0 || it == q.begin() || (--it)->b + 1 != s.a) {
			from[s.id] = -1;
			dp[s.id] = s.b - s.a + 1;
		} else {
			from[s.id] = it->id;
			dp[s.id] = dp[it->id]+ (s.b - s.a + 1);
		}
		q.insert(s);
	}

	cout << n - *max_element(dp, dp + sz(segs)) << endl;

    return 0;
}