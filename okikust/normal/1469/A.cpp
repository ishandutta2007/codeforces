#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 110
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t, n, x, z;
	bool v;
	char a[N];
	cin >> t;
	rep(tt, t) {
		rep(i, N)a[i] = 0;
		cin >> a;
		n = strlen(a);
		v = true;
		if (n % 2 == 1)v = false;
		z = n / 2;
		rep(i, n) {
			if (a[i] == '(')z--;
		}
		x = 0;
		rep(i, n) {
			if (a[i] == '(')x++;
			else if (a[i] == ')')x--;
			else {
				if (z > 0) {
					x++;
					z--;
				}
				else x--;
			}
			if (x < 0)v = false;
		}
		if (x != 0)v = false;
		if (v)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}