#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const ll MAXV = 10004205361450474;

//unordered_map<ll, ll> mem[6];

vector<ll> req;

ll rec(ll l, int q, bool flag = false) {
	if (q == 1) {
		if (flag) {
			int ops = min(l, 10000ll);
			for (int i = 0; i < ops; ++i) {
				req.push_back(l + i);
			}
		}
		return min(l, 10000ll);
	}
	/*
	if (mem[q].count(l)) {
		return l;
	}
	*/
	ll last = l;
	int ops = min(l, 10000ll);
	for (int i = 0; i <= ops; ++i) {
		ll tmp = rec(last, q - 1);
		if (flag && i) {
			req.push_back(last - 1);
		}
		last += tmp + 1;
		if (last > MAXV + 5) {
			last = MAXV + 5;
			break;
		}
	}
	--last;
	return last - l;
}

int cnt = 0;
int ask(vector<ll> v) {
	// cerr << szof(v) << endl;
	// if (szof(v) > 1) {
	// 	assert(false);
	// }
	// if (v[0] == 1) {
	// 	assert(1 == 2);
	// }
	// ++cnt;
	// assert(cnt < 5);
	// return 0;
	while (szof(v) && v.back() > MAXV) {
		v.pop_back();
	}
	cout << szof(v) << " ";
	for (auto num : v) {
		cout << num << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	if (res < 0) {
		exit(0);
	}
	return res;
}

//vector<ll> mem_req = {};

void solve() {
    ll part1 = rec(1, 4);
    
    int res = ask({part1 + 1});
    ll l = 0, r = 0;
    if (res == 0) {
    	l = 1, r = part1;
    } else {
    	l = part1 + 2, r = MAXV;
    }

    int k = 4;
    while (true) {
    	// cerr << k << endl;
    	req.clear();
    	if (k < 4 || l != part1 + 2) {
    		rec(l, k, true);
    	} else {
    		ll qwe = rec(l, k - 1);
    		ll last = l;
    		for (int i = 0; i <= 10000; ++i) {
    			if (i) {
    				req.push_back(last - 1);
    			}
    			last += qwe + 1;
    			if (last > MAXV + 5) {
					last = MAXV + 5;
					break;
				}
    		}
    		--last;
    	}
    	int res = ask(req);
    	// cerr << "here" << endl;
    	if (res) {
    		l = req[res - 1] + 1;
    	}
    	if (res < szof(req)) {
    		r = req[res] - 1;
    	}
    	--k;
    }
}


int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_count = 1;
    // cin >> test_count;
    for (int test = 1; test <= test_count; ++test) {
        solve();
    }
    
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}