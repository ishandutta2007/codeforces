#include "bits/extc++.h"

using namespace std;

template<class T, class U = less<T>>
using rt = __gnu_pbds::tree<T, __gnu_pbds::null_type, U, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<class T>
void dbgh(const T &t) {
	cerr << t << endl;
}

template<class T, class ...U>
void dbgh(const T &t, const U &...u) {
	cerr << t << " | ";
	dbgh(u...);
}

#ifdef DEBUG
#define dbg(...) cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]" << ": "; dbgh(__VA_ARGS__)
#else
#define cerr if(false) cerr
#define dbg(...) 1412
#endif

//imagine a language where int = long
#define long int64_t

//typing too hard
#define endl "\n"

#define sz(x) int((x).size())

long gcd(long a, long b) {
	if(a == 0 || b == 0) {
		return a ^ b;
	}
	return __gcd(a, b);
}

void solve() {
	int n;
	cin >> n;
	long arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mx = *max_element(arr, arr + n);
	long diff[n];
	for(int i = 0; i < n; i++) {
		diff[i] = mx - arr[i];
	}
	long ans = 0;
	for(int i = 0; i < n; i++) {
		ans = gcd(ans, diff[i]);
	}
	long x = 0;
	for(int i = 0; i < n; i++) {
		x += diff[i] / ans;
	}
	cout << x << " " << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::failbit);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t = 1;
//	cin >> t;
	for(int _ = 1; _ <= t; _++) {
		dbg(_);
//		cout << "Case #" << _ << ": ";
		solve();
	}
}