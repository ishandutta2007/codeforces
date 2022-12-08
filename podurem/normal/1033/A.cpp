#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
typedef long double ld;

using namespace std;

const int dd = (int)1e5 + 7;

int main() {
	int n;
	cin >> n;
	int ax, ay, bx, by, cx, cy;
	cin >> bx >> by >> ax >> ay >> cx >> cy;
	if ((ax > bx) == (cx > bx) && (ay > by) == (cy > by)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}