#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int shortest_path(int from, int to, int k) {
	vector<int> lvl(from - to + 1, -1);

	queue<int> q;
	q.push(from);
	lvl[from - to] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x - 1 >= to && lvl[x - to - 1] == -1) {
			lvl[x - to - 1] = 1 + lvl[x - to];
			q.push(x - 1);
		}

		for (int i = 2; i <= k; i++) {
			if (x - (x % i) >= to && lvl[x - (x % i) - to] == -1) {
				lvl[x - (x % i) - to] = 1 + lvl[x - to];
				q.push(x - (x % i));
			}
		}
	}
	return lvl[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	swap(a, b);

	int k;
	cin >> k;

	int lcm = 2;
	for (int i = 3; i <= k; i++) {
		lcm *= i / __gcd(i, lcm);
	}

	if (a >= b - b % lcm) {
		cout << shortest_path(b % lcm, a % lcm, k) << '\n';
	} else {
		ll ans = shortest_path(lcm, a % lcm, k) + shortest_path(b % lcm, 0, k);
		a += (lcm - a % lcm) % lcm;
		b -= b % lcm;
		ans += (b - a) / lcm * (ll)shortest_path(lcm, 0, k);
		cout << ans << '\n';
	}
	return 0;
}