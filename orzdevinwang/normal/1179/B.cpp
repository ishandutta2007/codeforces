#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 1, n / 2) {
		L(j, 1, m) {
			cout << i << ' ' << j << '\n';
			cout << n - i + 1 << ' ' << m - j + 1 << '\n';
		}
	}
	if(n % 2 == 1) {
		L(j, 1, m / 2) {
			cout << (n + 1) / 2 << ' ' << j << '\n';
			cout << (n + 1) / 2 << ' ' << m - j + 1 << '\n';
		}
		if(m % 2 == 1) {
			cout << (n + 1) / 2 << ' ' << (m + 1) / 2 << '\n';
		}
	}
	return 0;
}