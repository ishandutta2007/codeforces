#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, p;
int a[2222];

int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	vector<int> v;
	for (int u = 0; ; u++) {
		int j = 1;
		int c = 0;
		int t = 1;
		for (int i = 0; i < n; i++) {
			while (j <= n && a[j] <= u+i) {c++; j++;}
			if (c == 0) {t = 0; break;}
			if (c >= p) {t = 2; break;}
			c--;
		}
		if (t == 1) v.push_back(u);
		if (t == 2) break;
	}
	cout << v.size() << "\n";
	for (auto x : v) cout << x << " ";
	cout << "\n";
}