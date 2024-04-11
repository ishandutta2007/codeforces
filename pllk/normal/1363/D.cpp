#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int c[1111];

int ask(int a, int b) {
	cout << "? " << (b-a+1) << " ";
	for (int i = a; i <= b; i++) cout << i << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> vv;
		for (int i = 1; i <= k; i++) {
			int c;
			cin >> c;
			vector<int> v(c);
			for (int j = 0; j < c; j++) cin >> v[j];
			vv.push_back(v);
		}
		int m = ask(1,n);
		int a = 1;
		int b = n;
		while (a != b) {
			int k = (a+b)/2;
			int u = ask(a,k);
			if (u == m) b = k;
			else a = k+1;
		}
		vector<int> rr;
		for (auto v : vv) {
			bool ok = true;
			for (auto x : v) if (x == a) ok = false;
			int r;
			if (ok) {
				r = m;
			} else {
				for (int i = 1; i <= n; i++) c[i] = 1;
				for (auto x : v) c[x] = 0;
				cout << "? " << (n-v.size()) << " ";
				for (int i = 1; i <= n; i++) if (c[i]) cout << i << " ";
				cout << endl;
				cin >> r;
			}
			rr.push_back(r);
		}
		cout << "! ";
		for (auto x : rr) cout << x << " ";
		cout << endl;
		string s;
		cin >> s;
	}
}