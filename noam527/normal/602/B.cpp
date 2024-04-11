#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

int n, mx = -1, p1 = 0, p2 = 0;
vector<int> a;
multiset<int> v;
multiset<int>::iterator it1, it2;

int main() {
	ios::sync_with_stdio(0);
	cin >> n, a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	v.insert(a[0]), p2 = 0, mx = 1;
	it1 = v.begin(), it2 = v.end(), it2--;
	while (p2 < n) {
		if (*it2 - *it1 <= 1) {
			p2++;
			if (p2 < n) v.insert(a[p2]);
		}
		else {
			auto temp = v.find(a[p1]);
			v.erase(temp), p1++;
		}
		it1 = v.begin(), it2 = v.end(), it2--;
		if (*it2 - *it1 <= 1)
			mx = max(mx, (int)v.size());
	}
	mx = max(mx, (int)v.size());
	cout << mx << endl;
}