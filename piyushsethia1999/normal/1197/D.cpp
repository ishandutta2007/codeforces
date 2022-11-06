#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int maa = 0;
	for (int i = 0; i < m; ++i) {
		int ma = -1000000000000000ll, me = 0;
		for (int j = 0; j < n; ++j)
			if (j % m == i) a[j] -= k; 
		for (int j = i; j < n; ++j)
		{
			me += a[j];
			if (ma < me)
				ma = me;
			if (me < 0 && (j + 1) % m == i)
				me = 0;
		}
		maa = max(ma, maa);
		for (int j = 0; j < n; ++j)
			if (j % m == i) a[j] += k; 
	}
	cout << maa;
}