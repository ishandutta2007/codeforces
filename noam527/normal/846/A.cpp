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
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, a[100], cnt0[100], cnt1[100];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cnt0[0] = (a[0] & 1 ? 0 : 1), cnt1[n - 1] = (a[n - 1] & 1 ? 1 : 0);
	for (int i = 1; i < n; i++) {
		if (a[i] & 1) cnt0[i] = cnt0[i - 1];
		else cnt0[i] = cnt0[i - 1] + 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] & 1) cnt1[i] = cnt1[i + 1] + 1;
		else cnt1[i] = cnt1[i + 1];
	}

	int mx = max(cnt0[n - 1], cnt1[0]);
	for (int i = 1; i < n; i++)
		mx = max(mx, cnt0[i - 1] + cnt1[i]);
	cout << mx << endl;
}