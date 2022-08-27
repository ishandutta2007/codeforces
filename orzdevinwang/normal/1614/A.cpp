#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int n, l, r, k, a[N];
void Main () {
	int ns = 0;
	cin >> n >> l >> r >> k;
	L(i, 1, n) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	L(i, 1, n) {
		if(l <= a[i] && a[i] <= r) {
			if(k >= a[i]) k -= a[i], ns += 1;
		}
	}
	cout << ns << '\n'; 
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}