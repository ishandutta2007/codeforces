#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, m;
vector<vector<int>> a;

bool update(int x, int y) {
	a[x][y] = 1;
//	for (auto i : a) {
//		for (auto j : i) cout << j << " "; cout << endl;
//	}
//	cout << endl;
	int st1 = max(0, x - 2), en1 = min(n - 1, x + 2) - 2;
	int st2 = max(0, y - 2), en2 = min(n - 1, y + 2) - 2;
//	cout << "x " << x << " y " << y << endl << "st1 " << st1 << " en1 " << en1 << " st2 " << st2 << " en2 " << en2 << endl;
	for (int i = st1; i <= en1; i++) {
		for (int j = st2, val; j <= en2; j++) {
			val = 0;
			for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++) val += a[i + k][j + l];
			if (val == 9) return true;
		}
	}
	return false;
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(n, vector<int>(n, 0));
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		if (update(x - 1, y - 1)) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}