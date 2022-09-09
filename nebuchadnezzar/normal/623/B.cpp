#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e6 + 5;

int n;
ll a, b;
ll inp[MAXN];

ll try_it(ll num) {
	//cerr << "try: " << num << endl;
	ll ret = 0;
	int lg = n;
	int rg = -1;
	vector<int> bad;
	bad.resize(n);
 	for (int i = 0; i < n; ++i) {
 	 	if (inp[i] % num != 0) {
 	 	 	if ((inp[i] + 1) % num == 0 || (inp[i] - 1) % num == 0) {
 	 	 	 	++ret;
 	 	 	 	bad[i] = 1;
 	 	 	} else {
 	 	 	 	lg = min(lg, i);
 	 	 	 	rg = max(rg, i);
 	 	 	}
 	 	}
 	}
 	//cerr << "lg rg: " << lg << " " << rg << endl;
 	if (rg == -1) {
 		ll d[3];
 		memset(d, 0, sizeof d);
 	 	for (int i = 0; i < n; ++i) {
 	 		d[2] = min(d[2] + a * bad[i], d[1] + a * bad[i]);
 	 		d[1] = min(d[1] + b, d[0] + b);
 	 		d[0] += a * bad[i]; 	 		 	 		
 	 	}
 	 	//cerr << min(d[0], min(d[1], d[2])) << endl;
 	 	return min(d[0], min(d[1], d[2]));
 	} else {
 		ll bal = 0;
 		ll bestl = 0;
 		for (int i = lg - 1; i >= 0; --i) {
 		 	bal += b;
 		 	bal -= a * bad[i];
 		 	//bestl = min(bestl, bal);
 		 	if (bestl > bal) {
 		 	 	bestl = bal;
 		 	 	lg = i;
 		 	}
 		}
 		bal = 0;
 		ll bestr = 0;
 		for (int i = rg + 1; i < n; ++i) {
 		 	bal += b;
 		 	bal -= a * bad[i];
 		 	//bestr = min(bestr, bal);
 		 	if (bestr > bal) {
 		 	 	bestr = bal;
 		 	 	rg = i;
 		 	}
 		}
 		//cerr << lg << " " << rg << endl;
 		int sum = 0;
 		for (int i = 0; i < n; ++i) {
 		 	if (i < lg || i > rg) {
 		 	 	sum += bad[i];
 		 	}
 		}
 		//cerr << a << " " << sum << endl;
 		//cerr << b * (rg - lg + 1) + a * sum << endl;
 		return b * (rg - lg + 1) + a * sum;
 	}
 	return 1e18;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%I64d%I64d", &n, &b, &a);

	if (n == 1) {
	 	cout << 0 << "\n";
	 	return 0;
	}

	ll ans = 1e18;

	for (int i = 0; i < n; ++i) {
	 	int ai;
	 	scanf("%d", &ai);
		inp[i] = ai;
	}

	for (int i = -1; i <=  1; ++i) {
	 	ll tmp = inp[0] + i;
	 	for (int j = 2; j * j <= tmp; ++j) {
	 	 	if (tmp % j == 0) {
	 	 	 	ans = min(ans, try_it(j));
	 	 	}
	 	 	while (tmp % j == 0) {
	 	 	 	tmp /= j;
	 	 	}
	 	}
	 	if (tmp != 1) {
	 	 	ans = min(ans, try_it(tmp));
	 	}
	}

	for (int i = -1; i <=  1; ++i) {
	 	ll tmp = inp[n - 1] + i;
	 	for (int j = 2; j * j <= tmp; ++j) {
	 	 	if (tmp % j == 0) {
	 	 	 	ans = min(ans, try_it(j));
	 	 	}
	 	 	while (tmp % j == 0) {
	 	 	 	tmp /= j;
	 	 	}
	 	}
	 	if (tmp != 1) {
	 	 	ans = min(ans, try_it(tmp));
	 	}
	}

	cout << ans << "\n";

	return 0;
}