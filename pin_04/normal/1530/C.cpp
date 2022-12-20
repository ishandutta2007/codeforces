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

int b[N];
int a[N];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		for (int i = 1; i <= n; i++)
			cin >> b[i];

		sort(a + 1, a + n + 1, greater <int>());
		sort(b + 1, b + n + 1, greater <int>());

		int lo = -1;
		int hi = n;
		while (hi - lo > 1) {
			int mid = (lo + hi) >> 1;

			int sz = (n + mid) - (n + mid) / 4;
			int atot = 100 * min(sz, mid);

			for (int i = 1; i <= sz - mid; i++)
				atot += a[i];

			int btot = 0;
			for (int i = 1; i <= min(n, sz); i++)
				btot += b[i];
			
			if (atot >= btot)
				hi = mid;
			else 
				lo = mid;
		}
		cout << hi << "\n";
	}
	return 0;
}