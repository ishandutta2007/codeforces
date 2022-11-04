#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n;
int x1, x2;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> x1 >> x2;
    vector<pair<ld, int>> points_left, points_right;

    for (int i = 0; i < n; i++) {
    	ld k, b;
    	cin >> k >> b;
    	ld y1 = k * (x1 + EPS) + b;
    	ld y2 = k * (x2 - EPS) + b;
    	points_left.pb(mp(y1, i));
    	points_right.pb(mp(y2, i));
    }

    sort(points_left.begin(), points_left.end());
    sort(points_right.begin(), points_right.end());

    for (int i = 0; i < n; i++) {
    	if (points_left[i].second != points_right[i].second) {
    		cout << "YES\n";
    		return 0;
    	}
    }

    cout << "NO\n";
    return 0;
}