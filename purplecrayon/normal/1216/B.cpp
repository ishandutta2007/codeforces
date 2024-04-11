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

void solve() {
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n, greater<>());
	long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += arr[i].first * i + 1;
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i].second << " ";
	}
	cout << endl;
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