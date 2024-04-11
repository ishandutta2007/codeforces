#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, a[100][100], k;
int tot1 = 0, tot2 = 0;

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int j = 0, sum; j < m; j++) {
		sum = 0;
		vector<int> temp;
		for (int i = 0; i < k; i++) sum += a[i][j];
		if (a[0][j]) temp.push_back(sum);
		for (int i = k; i < n; i++) {
			sum = sum + a[i][j] - a[i - k][j];
			if (a[i - k + 1][j]) temp.push_back(sum);
		}
		for (int i = n - k + 1; i < n; i++) {
			sum -= a[i - 1][j];
			if (a[i][j]) temp.push_back(sum);
		}

//		cout << "column " << j << endl;
//		for (auto &i : temp) cout << i << " "; cout << endl;

		if (temp.size() == 0) continue;
		int mx = -2e9;
		for (auto &i : temp) mx = max(mx, i);

		int ind = -1;
		while (temp[++ind] != mx);
		tot1 += mx, tot2 += ind;
	}
	cout << tot1 << " " << tot2 << endl;
}