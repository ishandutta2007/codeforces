#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

#define MAXN 10000

struct point {
	ll x, y, id;

	point() : x(0), y(0), id(-1) {}

	point(ll x, ll y, ll id) : x(x), y(y), id(id) {}
};

bool sort_asc(const point &a, const point &b) {
	return a.y < b.y;
}

bool sort_desc(const point &a, const point &b) {
	return a.y > b.y;
}

int n;
vector<int> ans;
vector<point> points[1001];

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    ans.resize(n);
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	points[x / 1000].pb(point(x, y, i));
    }

    for (int i = 0; i < 1001; i++) {
    	auto sort_func = i & 1 ? sort_asc : sort_desc;
    	sort(points[i].begin(), points[i].end(), sort_func);

    	for (point p : points[i]) {
    		cout << p.id + 1 << " ";
    	}
    }

    cout << "\n";
    return 0;
}