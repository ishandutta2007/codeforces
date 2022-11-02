#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 5;
int n, w;
int a[sz];

void solve() {
	cin >> n >> w;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	priority_queue<ll> pq;
	ford(i, n - 1, 0) {
		if (!pq.empty() && pq.top() >= a[i]) {
			ll x = pq.top(); pq.pop();
			if(x!=a[i])pq.push(x - a[i]);
		}
		else {
			cnt++;
			if(w!=a[i])pq.push(w - a[i]);
		}
	}
	cout << cnt << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}