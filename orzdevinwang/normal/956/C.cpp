#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, U, E[N], W[N], m;
int sz[N];
void add (int x, int w) {
	for (; x <= n; x += x & -x) 
	 	sz[x] += w;
}
int query (int x) {
	int ret = 0;
	for(; x; x -= x & -x) 
		ret += sz[x];
	return ret; 
}
int a[N], b[N], w[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n;
	L(i, 1, n) cin >> a[i], b[i] = a[i], b[i] = max(b[i], b[i - 1]);
	R(i, n, 1) b[i] = max(b[i], b[i + 1] - 1);
	ll ns = 0;
	L(i, 1, n) {
		ns += b[i] - a[i];
	}
	cout << ns << '\n';
	return 0;
}