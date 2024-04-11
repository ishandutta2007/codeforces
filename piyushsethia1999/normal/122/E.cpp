#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long
using namespace std;

std::vector<int> v;

int c(int i) {
	while (i) {
		if (i % 10 == 4 || i % 10 == 7) {}
		else return 0;
		i /= 10;
	}
	return 1;
}

int MAXN = 1e10;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	std::vector<int> fact = {1ll, 1ll, 2ll, 6ll, 24ll, 120ll, 720ll, 5040ll, 40320ll, 362880ll, 3628800ll, 39916800ll, 479001600ll, 6227020800ll, 87178291200ll};
	priority_queue<int, std::vector<int>, greater<int> > pq;
	pq.push(4);
	pq.push(7);
	while (!pq.empty()) {
		int o = pq.top();
		pq.pop();
		v.pb(o);
		if (o * 10ll + 7ll <= MAXN) {
			pq.push(o * 10ll + 7ll);
			pq.push(o * 10ll + 4ll);
		} else if(o * 10ll + 4ll <= MAXN) {
			pq.push(o * 10ll + 4ll);
		}
	}
	int n; cin >> n;
	int k; cin >> k;
	if (n <= 13 && fact[n] < k) {
		cout << -1;
		exit(0);
	} 
	int rem = min(n, 13ll);
	std::vector<int> vv;
	for (int i = rem - 1; i >= 0; --i) {
		vv.pb(n - i);
	}
	int r = 0;
	for (int vvv : v)
		if (vvv <= (n - rem))
			r++;
	std::vector<int> v1;
	while (rem) {
		int y = 0;
		rem--;
		while (fact[rem] < k) {
			k -= fact[rem];
			y++;
		} 
		v1.pb(vv[y]);
		vv.erase(vv.begin() + y);
	}
	rem = min(n, 13ll);
	for (int i = 0; i < rem; ++i) {
		if (c(n - i) && c(v1[rem - i - 1])) {
			r++;
		}
	}
	cout << r;
}