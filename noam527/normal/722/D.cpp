#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int f(set<int> &a) {
	auto it = a.end();
	it--;
	int temp = *it / 2;
	while (temp >= 1 && a.find(temp) != a.end()) temp /= 2;
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	int n, v;
	set<int> a;
	cin >> n;
	while (n--) cin >> v, a.insert(v);
	v = f(a);
	while (v) {
		auto it = a.end();
		a.erase(--it), a.insert(v), v = f(a);
	}
	for (auto i = a.begin(); i != a.end(); i++) cout << *i << " "; cout << endl;
}