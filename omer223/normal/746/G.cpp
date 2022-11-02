
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int sz = 2e5 + 5;
int n, k, t, a[sz], posleave[sz], inst[sz];
vector<int> adj[sz];

int main() {
	fast;
	cin >> n >> t >> k;
	foru(i, 0, t)cin >> a[i+1];
	if (t == 1) {
		if (a[1] != k)cout << -1 << endl;
		else {
			cout << n << endl;
			foru(i, 1, n)cout << 1 << " " << i + 1 << endl;
		}
		return 0;
	}
	int mustRts = 0;
	a[0] = 1;
	posleave[0] = 0;
	foru(i, 1, t+1) {
		int myMust = max(0, a[i] - a[i + 1]);
		mustRts += myMust;
		posleave[i] = max(0, a[i] - 1 - myMust);
	}
	if (mustRts > k) {
		cout << -1 << endl;
		return 0;
	}
	foru(i, 1, t + 1) {
		inst[i] = min(posleave[i], max(0, k - mustRts));
		mustRts += inst[i];
	}
	if (mustRts != k) {
		cout << -1 << endl;
		return 0;
	}
	cout << n << endl;
	int cur = 1;
	vector<int> prv, now;
	foru(i, 0, a[1]) {
		adj[0].pb(cur);
		now.pb(cur++);
	}
	foru(i, 2, t + 1) {
		prv = now;
		now.clear();
		int totamt = a[i-1] - inst[i-1] - max(0, a[i - 1] - a[i]) , mycnt = 0;
		while (mycnt < a[i]) {
			now.pb(cur);
			adj[prv[min(mycnt, totamt-1)]].pb(cur++);
			mycnt++;
		}
	}
	foru(i, 0, n) {
		for (auto x : adj[i])cout << i + 1 << " " << x + 1 << endl;
	}
	return 0;
}