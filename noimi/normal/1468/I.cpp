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

ll gcd(ll x, ll y) {
	if (x < 0)x = -x;
	if (y < 0)y = -y;
	if (x > y)swap(x, y);
	if (x == 0)return y;
	return gcd(y%x, x);
}


int main() {
	ll n, a, b, c, d, g, x;
	cin >> n;
	cin >> a >> b;
	cin >> c >> d;
	g = abs(gcd(b, d));
	x = abs((a*d) - (b*c));
	if ((g!=0)&&(x == n)) {
		cout << "YES" << endl;
		rep(i, (x/g)) {
			rep(j, g)cout << i << " " << j << endl;
		}
	}
	else cout << "NO" << endl;
	return 0;
}