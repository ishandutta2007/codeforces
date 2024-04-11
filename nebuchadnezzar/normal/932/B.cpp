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

const int MAXN = 1e6 + 5;

int g(int num) {
	if (num < 10) {
		return num;
	}
	int tmp = 1;
	while (num) {
		if (num % 10) {
			tmp *= num % 10;
		}
		num /= 10;
	}
	return g(tmp);
}

vector<int> pref[10];

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    cout << upper_bound(pref[k].begin(), pref[k].end(), r) - lower_bound(pref[k].begin(), pref[k].end(), l) << "\n";
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAXN; ++i) {
    	pref[g(i)].push_back(i);
    }

    int tests = 1;
     cin >> tests;
    for (int it = 1; it <= tests; ++it) {
        solve();
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << " ms\n";
    #endif
    return 0;
}