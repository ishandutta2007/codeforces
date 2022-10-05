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
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

int n, mx = 2;
vector<int> a;
unordered_map<int, int> m;
queue<int> q;

int f(int k) { return k % 3; }

int check(int x, int y) {
	int cnt = 2, k[3];
	m[x]--, m[y]--;
	q.push(x), q.push(y);
	k[0] = x, k[1] = y;
	while (m[k[f(cnt + 1)] + k[f(cnt + 2)]]) {
		m[k[f(cnt + 1)] + k[f(cnt + 2)]]--;
		k[f(cnt)] = k[f(cnt + 1)] + k[f(cnt + 2)];
		q.push(k[f(cnt)]);
		cnt++;
	}
	while (!q.empty()) m[q.front()]++, q.pop();
	return cnt;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
	mx = max(mx, m[0]);
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i] != 0 || a[j] != 0) mx = max(max(mx, check(a[i], a[j])), check(a[j], a[i]));
	cout << mx << endl;
}