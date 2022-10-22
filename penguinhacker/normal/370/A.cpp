#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;
	cout << (r1==r2||c1==c2?1:2) << ' '; //rook
	if (((r1+c1)-(r2+c2))&1)
		cout << 0 << ' ';
	else
		cout << (c1-r1==c2-r2||r1+c1==r2+c2?1:2) << ' ';
	cout << max(abs(r1-r2), abs(c1-c2));
	return 0;
}