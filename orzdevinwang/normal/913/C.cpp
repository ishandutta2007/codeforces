#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, L;
ll c[N], suf[N];
ll Get (int x) {
	R(i, 30, 0) if(x >> i & 1) return suf[i + 1];
	return 0;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> L;
	suf[30] = 1e18;
	L(i, 0, 29) c[i] = 1e18;
	L(i, 0, n - 1) cin >> c[i]; 
	L(i, 1, 29) c[i] = min(c[i], c[i - 1] * 2);
	R(i, 29, 0) suf[i] = min(suf[i + 1], c[i]);
	ll ret = 0, ns = 1e18;
	R(i, 29, 0) if(L >> i & 1) ns = min(ns, Get(L) + ret), ret += c[i], L -= 1 << i;
	ns = min(ns, ret);
	cout << ns << '\n'; 
	return 0;
}