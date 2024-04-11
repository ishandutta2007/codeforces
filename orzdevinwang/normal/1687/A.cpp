#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, a[N];
ll k, pre[N], ns;
void Main () {
	ns = 0;
	cin >> n >> k;
	L(i, 1, n) cin >> a[i], pre[i] = a[i] + pre[i - 1];
	if(k >= n) {
		L(i, 1, n) ns += a[i] + k;
		ns -= (ll) n * (n + 1) / 2;
	} else {
		L(i, k, n) ns = max(ns, pre[i] - pre[i - k]);
		ns += (ll) k * (k - 1) / 2;
	} 
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie(0);
	int t ;
	cin >> t;
	while(t--) Main ();
	return 0;
}