#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
priority_queue<int, vector<int>, greater<int>> pq;
const int sz = 1e5;
int n;
ll k, a;
ll x[sz], c[sz];
int main() {
	fast;
	cin >> n >> k;
	foru(i, 0, n)cin >> x[i];
	cin >> a;
	foru(i, 0, n)cin >> c[i];
	ll mon = 0;
	bool bad = 0;
	foru(i, 0, n) {
		pq.push(c[i]);
		while (k < x[i] && !pq.empty()) {
			mon += pq.top(); pq.pop();
			k += a;
		}
		if (k < x[i]) {
			bad = 1;
			break;
		}
	}
	cout << (bad ? -1 : mon) << endl;
	return 0;
}