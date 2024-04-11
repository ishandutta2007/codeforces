#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, m, x, a[N], ns;
pair < int, int > arr[N];
int atot = 0;
void Main() {
	cin >> n >> x;
	int mx = -2e9, mn = 2e9, ns = 0;
	L(i, 1, n) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		if((ll) mx - mn > 2 * x) {
			ns += 1;
			mx = a[i], mn = a[i];
		}
	}
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}