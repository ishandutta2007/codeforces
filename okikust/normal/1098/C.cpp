#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	ll n, k, c;
	ll s;
	ll mi, ma;
	ll l, r, m, x, y;
	cin >> n >> s;
	mi = 2 * n - 1;
	ma = (n*(n + 1)) / 2;
	if ((s < mi) || (s > ma)) {
		cout << "No" << endl;
		return 0;
	}
	l = 0;
	r = n - 1;
	while (l + 1 < r) {
		m = (l + r) / 2;
		if (m == 1)k = ma;
		else {
			y = 1;
			k = 0;
			c = 1;
			x = n;
			while (x > y) {
				x -= y;
				k += (c*y);
				y *= m;
				c++;
			}
			k += (c*x);
		}
		if (k <= s)r = m;
		else l = m;
	}
	ll d[N];
	ll itr, mx,ss;
	ss = 0;
	rep(i, n) {
		d[i] = 1;
		ss += (i + 1);
	}
	if (r > 1) {
		itr = 1;
		mx = r;
		rep3(i, n - 1, 1) {
			if (d[itr] >= mx) {
				itr++;
				mx *= r;
			}
			if ((ss - (i - itr)) > s) {
				d[i]--;
				d[itr]++;
              ss-=(i - itr);
			}
			else {
				d[i]--;
				d[(i - (ss - s))]++;
                break;
			}
		}
	}
	ll p[N];
	ll st, sst;
	ll itr2;
	itr = 0;
	st = 1;
	rep2(i, 1, n - 1) {
		itr2 = st;
		st = itr + 2;
		sst = 0;
		rep(j, d[i]) {
			p[itr] = itr2;
			sst++;
			itr++;
			if (sst >= r) {
				itr2++;
				sst = 0;
			}
		}
	}
	cout << "Yes" << endl;
	rep(i, n - 2)cout << p[i] << " ";
	cout << p[n - 2] << endl;
	
	return 0;
}