#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <fstream>
#include <random>
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

int n, k, a[101] = {}, len;
string s;

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[s.size()]++;
	}
	cin >> s, len = s.size();

	int tot1 = 0, tot2;
	for (int i = 0; i < len; i++) tot1 += a[i];
	tot2 = tot1 + a[len];

	int cnt = 1;
	for (int i = 0; i < tot1; i++) {
		if ((i + 1) % k == 0) cnt += 6;
		else cnt++;
	}
	cout << cnt << " ";
	cnt = 1;
	for (int i = 0; i < tot2 - 1; i++) {
		if ((i + 1) % k == 0) cnt += 6;
		else cnt++;
	}
	cout << cnt << endl;
}