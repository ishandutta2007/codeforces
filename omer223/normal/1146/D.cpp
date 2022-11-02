#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <queue>
#include <numeric>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int mxSize = 3e5;
ll a, b, m, g;
int times[mxSize];

void bfs(int src, int time) {
	queue<int> q;
	times[src] = time;
	q.push(src);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x + a <= time && times[x + a] == -1) {
			times[x + a] = time;
			q.push(x + a);
		}
		if (x - b >= 0 && times[x - b] == -1){
			times[x - b] = time;
			q.push(x - b);
		}
	}
}

void prec() {
	foru(i, 1, mxSize)times[i] = -1;
	foru(i, 1, mxSize) {
		if (i >= a && times[i - a] != -1) bfs(i, i);
	}
}

int getMaxTime() {
	int ans = 0;
	for (int i = 1; i < a; i++) {
		if (i%g)continue;
		ans = max(ans, times[i]);
	}
	return ans;
}

ll calcSum(ll l, ll r) {
	if (l > r)return 0;
	ll ans = (r - l + 1);
	if (r - l <= 2 * g) {
		for (int i = l; i <= r; i++)ans += (i / g);
	}
	else {
		ll rem;
		if (l%g) {
			rem = g - l % g;
			ans += rem * (l / g);
			l += rem;
		}
		if (r%g!=g-1) {
			rem = r - (r / g)*g+1;
			ans += rem * (r / g);
			r -= rem;
		}
		ll gap = (r - l + 1) / g, fi = l / g, la = r / g;
		ans += g * (((fi + la)*gap) / 2);
	}
	return ans;
}

int main() {
	fast;
	cin >> m >> a >> b; g = gcd(a, b);
	prec();
	int maxTime = getMaxTime();
	ll tot = 0;
	if (maxTime > m) {
		foru(i, 0, m+1) {
			if (times[i] != -1&&times[i]<=m)tot += (m - times[i] + 1);
		}
	}
	else {
		foru(i, 0, maxTime+1) {
			if (times[i] != -1&&times[i]<=maxTime)tot += (maxTime - times[i] + 1);
		}
		tot += calcSum(maxTime + 1, m);
	}
	cout << tot << endl;
	return 0;
}