#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//
vector <long long> a;
long long l, r;
long long sum;
//
long long min(long long a, long long b) {
	if (a < b) return a; else return b;
}
//
void gen(long long x) {
	a.push_back(x);
	if (x <= 1e9) {
		gen(x*10+4);
		gen(x*10+7);
	}
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> l >> r;
	gen(4);
	gen(7);
	sort(a.begin(), a.end());
	//
	sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (min(r, a[i]) >= l) {
			sum += (min(r, a[i])+1-l)*a[i];
			l = min(r, a[i])+1;
		}
	}
	cout << sum << endl;
	//
	return 0;
}