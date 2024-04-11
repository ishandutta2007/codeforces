#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 5e2 + 2;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	string s; cin >> s;
	vector <int> a;
	for (auto& x : s) {
		a.push_back(x - 'a');
	}
	for (int i = 50; i >= 0; --i) {
		vector <int> b;
		for (auto& x : a) {
			if (!b.empty() and b.back() == x - 1 and b.back() == i / 2) {
				continue;
			}
			else {
				b.push_back(x);
			}
		}
		a = b;
		reverse(a.begin(), a.end());
	}
	cout << n - a.size() << '\n';
}