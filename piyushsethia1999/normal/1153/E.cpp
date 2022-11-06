#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int n;
	cin >> n;
	return n;
}

void prin(int x1, int y1, int x2, int y2) {
	cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	exit(0);
}
int32_t main()
{
	int n; cin >> n;
	if (n == 1) {
		prin(1, 1, 1, 1);
	} 
	int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
	for (int i = 1; i <= n; ++i) {
		if (r2 > 0) break;
		if (i == n && r1 > 0) {
			r2 = n;
			break;
		}  
		int y = ask(1, i, n, i);
		if (y & 1) {
			if (r1 < 0) {
				r1 = i;
			} else {
				r2 = i;
			}
		}
	}
	if (r1 > 0 && r2 > 0) {
		int s = 1; int e = n;
		while (s < e) {
			int m = (s + e) >> 1;
			int y = ask(s, r1, m, r1);
			if (y & 1) {
				e = m;
			} else {
				s = m + 1;
			}
		}
		c1 = s;
		s = 1, e = n;
		while (s < e) {
			int m = (s + e) >> 1;
			int y = ask(s, r2, m, r2);
			if (y & 1) {
				e = m;
			} else {
				s = m + 1;
			}
		}
		c2 = s;
		prin(c1, r1, c2, r2);
	} 
	for (int i = 1; i <= n; ++i) {
		if (c2 > 0) break;
		if (i == n && c1 > 0) {
			c2 = n;
			break;
		}  
		int y = ask(i, 1, i, n);
		if (y & 1) {
			if (c1 < 0) {
				c1 = i;
				// cout << y << "c1\n";
			} else {
				c2 = i;
				// cout << y << "c2\n";
			}
		}
	}
	int s = 1; int e = n;
	// cout << r1 << " " << r2 << endl;
	// cout << c1 << " " << c2 << endl;
	while (s < e) {
		int m = (s + e) >> 1;
		int y = ask(c1, s, c1, m);
		if (y & 1) {
			e = m;
		} else {
			s = m + 1;
		}
	}
	r1 = s;
	s = 1, e = n;
	while (s < e) {
		int m = (s + e) >> 1;
		int y = ask(c2, s, c2, m);
		if (y & 1) {
			e = m;
		} else {
			s = m + 1;
		}
	}
	r2 = s;
	prin(c1, r1, c2, r2);
}