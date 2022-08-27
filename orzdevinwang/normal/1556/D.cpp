#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, k, a[N];
int sum (int i, int j) {
	int ret = 0, s = 0;
	cout << "or " << i << " " << j << endl;
	cin >> ret;
	cout << "and " << i << " " << j << endl;
	cin >> s;
	return ret + s;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ll x = sum (1, 2), y = sum(2, 3), z = sum(3, 1);
	a[1] = (x + z - y) / 2; 
	a[2] = x - a[1];
	a[3] = y - a[2];
	L(i, 4, n) a[i] = sum(1, i) - a[1];
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << endl;
	return 0;
}