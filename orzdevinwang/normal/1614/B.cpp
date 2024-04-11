#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int n, m, a[N], ns[N], ord[N];
void Main () {
	cin >> n ;
	L(i, 1, n) 
		cin >> a[i];
	L(i, 1, n) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return a[x] > a[y];
	});
	ll ret = 0;
	L(i, 1, n) {
		int u = ord[i];
		int w = (i + 1) / 2;
		if(i & 1) w = -w;
		ns[u] = w;
		ret += (ll) abs (w) * a[u];
	}
	cout << ret * 2 << '\n';
	L(i, 0, n) cout << ns[i] << ' ';
	cout << '\n';
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}