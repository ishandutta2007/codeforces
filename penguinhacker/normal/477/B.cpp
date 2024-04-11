#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	cout << k*(6*n-1) << "\n";
	for (int i=0; i<n; ++i) {
		for (int j : {1, 2, 3, 5})
			cout << (i*6+j)*k << " ";
		cout << "\n";
	}
	return 0;
}