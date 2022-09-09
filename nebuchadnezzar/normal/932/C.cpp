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


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int numa = -1, numb = -1;
    for (int i = 0; i * a <= n; ++i) {
    	if ((n - a * i) % b == 0) {
    		numa = i;
    		numb = (n - a * i) / b;
    		break;
    	}
    }
    if (numa == -1) {
    	cout << "-1\n";
    	return;
    }
    int cnt = 1;
    for (int i = 0; i < numa; ++i) {
    	int mem = cnt++;
    	for (int j = 0; j < a - 1; ++j) {
    		cout << cnt++ << " ";
    	}
    	cout << mem << " ";
    }
    for (int i = 0; i < numb; ++i) {
    	int mem = cnt++;
    	for (int j = 0; j < b - 1; ++j) {
    		cout << cnt++ << " ";
    	}
    	cout << mem << " ";
    }
    cout << "\n";
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