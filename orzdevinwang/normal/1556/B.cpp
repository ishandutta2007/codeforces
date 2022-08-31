#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, a[N], nt[2], f[N];
int sz[N];
void add (int x) {
	for(; x <= n; x += x & -x) 
		sz[x] += 1;
}
int qzh (int x) {
	int ret = 0;
	for(; x; x -= x & -x) 
		ret += sz[x];
	return ret;
}
ll calc () {
	L(i, 1, n) sz[i] = 0;
	ll res = 0;
	L(i, 1, n) add(f[i]), res += i - qzh(f[i]);
	return res;
} 
void Main () {
	ll ns = 1e18;
	cin >> n;
	int cnt = 0;
	L(i, 1, n) cin >> a[i], a[i] &= 1, cnt += a[i];
	if(n % 2 == 0) {
		if(cnt != n / 2) return cout << -1 << '\n', void();
		else {
			nt[0] = 0, nt[1] = 0;
			L(i, 1, n) 
				f[i] = ++nt[a[i]], f[i] = f[i] * 2 - (a[i] == 1);
			ns = calc ();
			nt[0] = 0, nt[1] = 0;
			L(i, 1, n) 
				f[i] = ++nt[a[i]], f[i] = f[i] * 2 - (a[i] == 0);
			ns = min(ns, calc());
		}
	}
	else {
		if(cnt != n / 2 && cnt != n / 2 + 1) return cout << -1 << '\n', void();
		bool op = cnt == (n / 2 + 1);
		nt[0] = 0, nt[1] = 0;
		L(i, 1, n) 
			f[i] = ++nt[a[i]], f[i] = f[i] * 2 - (a[i] == op);
		ns = calc();
	}
	cout << ns << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}