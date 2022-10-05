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
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

struct star {
	int x, y;
	star(int x = 0, int y = 0) : x(x), y(y) {};
	bool operator < (star &a) {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};

int n, m, k;
string s[300];

vector<star> a[301];

void print(int x, int y) {
	cout << x + 1 << " " << y + 1 << endl;
}

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') {
				vector<int> t;
				for (int k = 1; i - k >= 0 && i + k < n; k++)
					if (s[i - k][j] == '*' && s[i + k][j] == '*') t.push_back(k);
				for (auto &k : t)
					if (j - k >= 0 && j + k < m && s[i][j - k] == '*' && s[i][j + k] == '*')
						a[k].push_back(star(i, j));
			}
		}
	}

	int at = 1;
	while (at <= 300 && k > a[at].size()) k -= a[at++].size();
	if (at == 301) return cout << -1 << endl, 0;
	sort(a[at].begin(), a[at].end());
	print(a[at][k - 1].x, a[at][k - 1].y);
	print(a[at][k - 1].x - at, a[at][k - 1].y);
	print(a[at][k - 1].x + at, a[at][k - 1].y);
	print(a[at][k - 1].x, a[at][k - 1].y - at);
	print(a[at][k - 1].x, a[at][k - 1].y + at);
}