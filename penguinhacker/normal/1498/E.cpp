#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k[501];

bool qry(int a, int b) {
	cout << "? " << a << " " << b << endl;
	string res; cin >> res;
	return res == "Yes";
}

vector<ar<int, 2>> t[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			t[abs(k[i] - k[j])].push_back({j, i});
	for (int i = n - 1; i >= 0; --i) {
		for (ar<int, 2> p : t[i]) {
			int a = p[0], b = p[1];
			if (k[a] > k[b])
				swap(a, b);
			if (qry(b, a)) {
				cout << "! " << a << " " << b << endl;
				return 0;
			}
		}
	}
	cout << "! 0 0" << endl;
	return 0;
}