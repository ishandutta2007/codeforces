#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
int gcd (long long a, long long b, long long & x, long long & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
//
long long a, b, c, x, y;
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
		cin >> a >> b >> c;
		long long g = gcd(a, b, x, y);
		if (c % g ==0) {
			cout << -x*(c/g) << " " << -y*(c/g) << endl;
		} else cout << -1;
}