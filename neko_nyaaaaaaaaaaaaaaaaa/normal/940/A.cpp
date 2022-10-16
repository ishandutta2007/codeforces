#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, d;
	cin >> n >> d;
	int ans = 1000;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[j] - a[i] <= d) {
				if (n - (j-i+1) < ans) {ans = n - (j-i+1);}
			}
		}
	}
	cout << ans;
	
	return 0;
}