#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t = 0;
	cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (a[i].first == a[j].second) t++;
			}
		}
	}
	cout << t;
}