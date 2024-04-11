#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if ((bx>ax ? 1:0) == (cx>ax ? 1:0) && (by>ay ? 1:0) == (cy>ay ? 1:0)) {
        cout << "YES" << '\n';
        return 0;
    }
	cout << "NO" << '\n';
	return 0;
}