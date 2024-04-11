#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m;
	vector<int> c(100005, 0), a(100005, 0);
	cin >> n >> m;
	int x;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (c[a[i]] == 0) {ans++;}
		c[a[i]]++;
	}
	vector<int> b(n, 0);
	for (int i = 0; i < n; i++) {
		b[i] = ans;
		c[a[i]]--;
		if (c[a[i]] == 0) {ans--;}
	}
	while (m--) {
		cin >> x;
		cout << b[x-1] << "\n";
	}
	
	return 0;
}