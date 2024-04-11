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

const int MAXN = 5e5 + 5, bp = 20;

int binup[bp][MAXN];
ll sumup[bp][MAXN];
int weight[MAXN], depth[MAXN];

void solve() {
    int q;
    cin >> q;
    int last = 0;
    int cnt = 1;
    depth[0] = 1;
    for (int qqq = 0; qqq < q; ++qqq) {
    	int type;
    	ll pp, qq;
    	cin >> type >> pp >> qq;
    	if (type == 1) {
    		int r = pp ^ last; --r;
    		int w = qq ^ last;
    		int p = r;
    		for (int i = bp - 1; i >= 0; --i) {
    			if (weight[binup[i][p]] < w) {
    				p = binup[i][p];
    			}
    		}
    		if (weight[p] < w) {
    			p = binup[0][p];
    		}
    		if (weight[p] < w) {
    			p = cnt;
    		}
    		//cerr << "add edge " << cnt << " " << p << endl;
    		binup[0][cnt] = p;
    		weight[cnt] = w;
    		sumup[0][cnt] = w;
    		depth[cnt] = depth[p] + 1;
    		for (int i = 1; i < bp; ++i) {
    			binup[i][cnt] = binup[i - 1][binup[i - 1][cnt]];
    			sumup[i][cnt] = sumup[i - 1][cnt] + sumup[i - 1][binup[i - 1][cnt]];
    		}
    		++cnt;
    	} else {
    		int r = pp ^ last; --r;
    		ll x = qq ^ last;
    		int ans = 0;
    		ll sum = 0;
    		int pos = r;
    		for (int i = bp - 1; i >= 0; --i) {
    			if (ans + (1 << i) <= depth[r] && sum + sumup[i][pos] <= x) {
    				sum += sumup[i][pos];
    				pos = binup[i][pos];
    				ans += (1 << i);
    			}
    		}
    		cout << ans << "\n";
    		last = ans;
    	}
    }
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