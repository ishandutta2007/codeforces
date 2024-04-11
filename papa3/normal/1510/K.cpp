#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

int n;
vector<int> v;

int foo(int gl, bool is1) {
	if (gl > 2 * n + 100) {
		return INF;
	}
	
	bool czy = true;
	for (int i = 0; i < 2 * n; i++) {
		if (v[i] != i + 1) {
			czy = false;
			break;
		}
	}
	if (czy) {
		return 0;
	}
	
	if (is1) {
		for (int i = 0; i < 2 * n; i+=2) {
			swap(v[i], v[i + 1]);
		}
	} else {
		for (int i = 0; i < n; i++) {
			swap(v[i], v[i + n]);
		}
	}
	return 1 + foo(gl + 1, is1 ^ 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> vv;
    
    cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int a;
		cin >> a;
		vv.push_back(a);
	}
    
    v = vv;
    int res = foo(0, false);
    
    v = vv;
    mini(res, foo(1, true));
    
    if (res >= INF) {
		cout << "-1\n";
	} else {
		cout << res << "\n";
	}
	
    
    return 0;
}/*

*/