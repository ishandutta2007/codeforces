#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

ll n, a[1000];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	bool supergood = false;
	for (int i = 1; i < n; i++) {
		ldb m = (ldb)(a[i] - a[0]) / i;
		vector<int> b;
		for (int j = 0; j < n; j++)
			if (m * j + a[0] != a[j]) b.push_back(j);
		if (b.size() > 0) {
			bool good = true;
			for (int j = 1; j < b.size() && good; j++)
				if (a[b[j - 1]] + m * (b[j] - b[j - 1]) != a[b[j]]) good = false;
			supergood = supergood || good;
		}
	}
	if (n >= 3 && a[2] - a[1] != a[1] - a[0]) {
		bool good = true;
		for (int i = 3; i < n && good; i++)
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) good = false;
		supergood = supergood || good;
	}

	if (supergood) cout << "Yes" << endl;
	else cout << "No" << endl;
}