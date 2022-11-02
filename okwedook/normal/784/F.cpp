#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	sort(arr.begin(), arr.end());
	while (clock() < 1500);
	for (auto i : arr) cout << i << ' ';
	return 0;
}