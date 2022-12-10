//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	s += 'X';
	vector<int> vec;
	int cnt = 0;
	for (auto c : s) {
		if (c == 'X') {
			if (cnt >= b)
				vec.PB(cnt);
			cnt = 0;
		}
		else
			cnt++;
	}
	int cnt2b = 0;
	for (auto len : vec) {
		cnt2b += len >= b + b;
		if (len >= b and len < a)
			return cout << "NO\n", 0;
	}
	if (cnt2b > 1)
		return cout << "NO\n", 0;
	int id = max_element(all(vec)) - vec.begin();
	int mxval = (sz(vec) ? vec[id] : 1e9);
	if (a > mxval)
		return cout << "NO\n", 0;
	if (cnt2b) {
		vec.erase(vec.begin() + id);
		bool aa = (mxval >= 3 * a and mxval <= a + 4 * b - 2);
		bool ba = false;
		for (int le = 0; le < b; le++) {
			int rem = mxval - (a + le);
			if (rem < 2 * b and rem >= a)
				ba = true;
		}
		bool bb = (mxval <= a + b + b - 2);
		if (((sz(vec) & 1) and ba) or ((sz(vec) & 1 ^ 1) and (aa or bb)))
			return cout << "YES\n", 0;
		return cout << "NO\n", 0;
	}
	else
		return cout << (sz(vec) & 1 ? "YES\n" : "NO\n"), 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}