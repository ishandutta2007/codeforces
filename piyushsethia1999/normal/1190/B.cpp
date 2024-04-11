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
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	int cn = 0;
	int in = -1;
	for (int i = 1; i < n; ++i)
		if (a[i] == a[i - 1]) 
			cn++, in = i;
	if (n >= 2 && a[0] == 0 && a[1] == 0) {
		cout << "cslnb\n";
		exit(0);
	} 
	if (cn > 1) {
		cout << "cslnb\n";
		exit(0);
	} else if (cn == 1) {
		if (in != 1 && ((a[in - 2] + 1) == a[in - 1])) {
			cout << "cslnb\n";
			exit(0);
		}
	} 
	int ans = a[0];
	a[0] = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1] || a[i] == (a[i - 1] + 1ll)) continue;
		ans = ans + (a[i] - (a[i - 1] + 1ll));
		a[i] = a[i - 1] + 1ll;
	}
	if (ans & 1ll)
		cout << "sjfnb\n";
	else
		cout << "cslnb\n";
}