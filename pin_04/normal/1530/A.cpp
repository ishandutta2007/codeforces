#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {
	if (a > b) {a = b; return true;} return false;
}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {
	if (a < b) {a = b; return true;} return false;
}
const int N = 1e5 + 5; 
const int oo = 1e9;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x = 0;
		while (n) {
			maxi(x, n % 10);
			n /= 10;
		}
		cout << x << "\n";
	}
	return 0;
}