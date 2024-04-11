#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	vector<ll> p={0};
	for (int i : a)
		p.push_back(p.back()+i);
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << p[n-(x-y)]-p[n-x] << "\n";
	}
	return 0;
}