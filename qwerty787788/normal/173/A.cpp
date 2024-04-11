#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int n, x, y, lc, it1, it2;
string s1, s2;
long long su1, su2, lcd;

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

long long lcm(long long x, long long y) {
	return x / gcd(x, y) * y;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s1;
	cin >> s2;
	x = s1.length();
	y = s2.length();
	lc = lcm(x, y);
	it1 = 0; it2 = 0;
	for (int i = 0; i < lc; i++) {
		char c1 = s1[it1];
		char c2 = s2[it2];
		if (c1=='R' && c2=='S') su2++;
		if (c1=='R' && c2=='P') su1++;
		if (c1=='P' && c2=='S') su1++;
		if (c2=='R' && c1=='S') su1++;
		if (c2=='R' && c1=='P') su2++;
		if (c2=='P' && c1=='S') su2++;
		it1 = (it1 + 1) % x;
		it2 = (it2 + 1) % y;
	}
	su1 *= (n / lc);
	su2 *= (n / lc);
	for (int i = 0; i < n % lc; i++) {
		char c1 = s1[it1];
		char c2 = s2[it2];
		if (c1=='R' && c2=='S') su2++;
		if (c1=='R' && c2=='P') su1++;
		if (c1=='P' && c2=='S') su1++;
		if (c2=='R' && c1=='S') su1++;
		if (c2=='R' && c1=='P') su2++;
		if (c2=='P' && c1=='S') su2++;
		it1 = (it1 + 1) % x;
		it2 = (it2 + 1) % y;
	}
	cout << su1 << " " << su2 << endl;
}