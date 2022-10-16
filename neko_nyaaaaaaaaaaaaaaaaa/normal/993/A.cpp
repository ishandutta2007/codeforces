#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int up = -1000, down = 1000, left = 1000, right = -1000;
	
	for (int i = 0; i < 4; i++) {
		int x, y;
		cin >> x >> y;
		up = max(up, y);
		down = min(down, y);
		left = min(left, x);
		right = max(right, x);
	}
	//cout << up << " " << down << " " << left << " " << right << endl;
	
	int u = -1000, d = 1000, l = 1000, r = -1000;
	for (int i = 0; i < 4; i++) {
		int x, y;
		cin >> x >> y;
		u = max(u, y);
		d = min(d, y);
		l = min(l, x);
		r = max(r, x);
	}
	//cout << u << " " << d << " " << l << " " << r << endl;
	
	int midy = (u + d)/2, midx = (l + r)/2;
	
	//cout << midx << " " << midy << endl;
	bool flag = 0;
	for (int x = midx, y = midx, k = u; k >= midy; k--, x--, y++) {
		// point coors are (k, x) and (k, y)
		//cout << k << " " << x << " " << y << endl;
		for (int i = x; i <= y; i++) {
			if (i <= right && i >= left && k >= down && k <= up) {cout << "YES"; return 0;}
		}
	}
	
	for (int x = r, y = l, k = midy; k >= d; k--, x--, y++) {
		// point coors are (k, x) and (k, y)
		//cout << k << " " << x << " " << y << endl;
		for (int i = y; i <= x; i++) {
			if (i <= right && i >= left && k >= down && k <= up) {cout << "YES";  return 0;}
		}
	}
	
	cout << "NO";
	
	return 0;
}