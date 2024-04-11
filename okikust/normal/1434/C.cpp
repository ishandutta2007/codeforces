#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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
	int t;
	ll a, b, c, d, r, k, s;
	ll x, y, z, ans;
	cin >> t;
	rep(tt, t) {
		cin >> a >> b >> c >> d;
		k = c / d;
		r = c % d;
		x = b * k*d - a;
		if (x >= 0) {
			x = a / (b * d);
			s = x * (x + 1);
			s = s / 2;
			s *= b;
			s *= d;
			s = ((x + 1)*a) - s;
			s = max(s, a);
		}
		else {
			x = b * c;
			if (x < a) {
				s = -1;
			}
			else {
				x = k;
				s = x * (x + 1);
				s = s / 2;
				s *= b;
				s *= d;
				s = ((x + 1)*a) - s;
				s = max(s, a);
			}
		}
		cout << s << endl;
	}
	return 0;
}