#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool same(long long p, long long q, vector<long long> const & a) {
	if (a.size() == 0) {
		return q == 0;
	}
	if (q == 0)
		return false;
	if (p < q)
		return false;
	long long first = a[0];
	vector<long long> b;
	for (int i = 1; i < a.size(); i++)
		b.push_back(a[i]);
	if (p / q < first)
		return false;
	p -= q * first;
	return same(q, p, b);
}

int main() {
	long long p, q;
	cin >> p >> q;
	int n;
	cin >> n;
	vector<long long> a;
	for (int i= 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	if (same(p, q, a)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}