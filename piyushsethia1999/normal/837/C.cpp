#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
int a, b;
bool ch(int x, int y, int x1, int y1) {
	if ((x + x1 <= a && max(y, y1) <= b) || (y + y1 <= b && max(x, x1) <= a)) return true;
	return false; 
}
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	cin >> a;
	cin >> b;
	int x[n], y[n];
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int ma = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (ch(x[i], y[i], x[j], y[j]) || ch(x[i], y[i], y[j], x[j]) || ch(y[i], x[i], x[j], y[j]) || ch(y[i], x[i], y[j], x[j])) 
				ma = max(ma, x[i] * y[i] + x[j] * y[j]);
		}
	}
	cout << ma;
}