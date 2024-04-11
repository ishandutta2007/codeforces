#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, m, k, a[N], mx[N], px[N];
int calc (int l, int r) {
	int ns = 1e9;
	L(i, 0, m) 
		ns = min(ns, max(a[l + i], a[r - (m - i)]));
	return ns;
}
void Main () {
	cin >> n >> m >> k;
	m -= 1, k = min(k, m), m -= k;
	L(i, 1, n) cin >> a[i];
	int ns = 0;
	L(i, 0, k) 
		ns = max(ns, calc (i + 1, n - (k - i)));
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}