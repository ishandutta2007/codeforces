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
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

bool found;
int n, d, lim = 77, ans[100002], a[100002], b[100002], p[100002], mx;
ll x;
vector<int> im;

void nextx() {
	x = (37 * x + 10007) % md;
}

void init() {
    int temp, ind;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	for (int i = 0; i < n; i++) {
		nextx();
		ind = x % (i + 1);
		temp = a[i], a[i] = a[ind], a[ind] = temp;
	}

	for (int i = 0; i < n; i++)
		b[i] = i < d;
	for (int i = 0; i < n; i++) {
		nextx();
		ind = x % (i + 1);
		temp = b[i], b[i] = b[ind], b[ind] = temp;
	}

	for (int i = 0; i < n; i++) {
		if (b[i]) im.push_back(i);
		p[a[i]] = i;
	}
}

int main() {
	fast;
	cin >> n >> d >> x;
	init();

	for (int i = 0; i < n; i++) {
		found = false;
		for (int j = n, l = max(1, n - lim); !found && j >= l; j--) {
			if (i >= p[j] && b[i - p[j]]) {
				ans[i] = j;
				found = true;
			}
		}
		if (!found) {
			mx = 0;
			for (int j = 0; j < im.size() && i >= im[j]; j++)
			    if (a[i - im[j]] > mx) mx = a[i - im[j]];
			ans[i] = mx;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << endl;
}