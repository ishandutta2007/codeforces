#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
int n, a[N];
ll x[N];
ll calc(int pn) {
	ll lst = 0, ret = 0;
	L(j, 1, pn) {
		ll t = (lst + x[j] - 1) / x[j];
		ret += t;
		lst = t * x[j] + 1;
	}
	return ret;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	ll ns = 1e18;
	L(i, 1, n) {
		L(j, 1, i) x[j] = a[i - j + 1];
		ll A = calc(i);
		L(j, 1, n - i + 1) x[j] = a[j + i - 1];
		ns = min(ns, A + calc(n - i + 1));
	} 
	cout << ns << '\n';
	return 0;
}