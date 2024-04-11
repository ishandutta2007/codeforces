#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int n, m, k, a[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) cin >> a[i];
	ll sum = a[n] - a[1];
	L(i, 1, n - 1) a[i] = a[i + 1] - a[i];
	sort (a + 1, a + n), reverse(a + 1, a + n);
//	cout << a[1] << ' ' << a[2] << '\n';
	L(i, 1, k - 1) sum -= a[i];
	cout << sum + k << "\n";
	
	return 0;
}