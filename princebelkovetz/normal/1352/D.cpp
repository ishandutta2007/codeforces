#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void solve() {
	int n, l, r, s1 = 0, s2 = 0, s11 = 0, s12 = 0, cou = 0;
	bool c = true;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	l = 0; r = n - 1;
	while (c) {
		if (c and s12 >= s11) cou++;
		while (s11 <= s12 and c) {
			s1 += a[l]; s11 += a[l];
			l++;
			if (l == r) {
				if (s12 >= s11) s1 += a[r];
				else { s2 += a[r]; cou++; }
				c = false;
			}
			if (l == n) c = false;

		}
		s12 = 0;
		if (c and s12 <= s11) cou++;
		while (c and s12 <= s11) {
			s2 += a[r]; s12 += a[r];
			r--;
			if (r == l) {
				if (s12 <= s11) s2 += a[r];
				else { s1 += a[r]; cou++; }
				c = false;
			}
			if (r == -1) c = false;
			
		}
		s11 = 0;
		//cout << cou << " " << s1 << " " << s2 << endl;
	}
	cout << cou << " " << s1 << " " << s2 << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) { solve(); }


}