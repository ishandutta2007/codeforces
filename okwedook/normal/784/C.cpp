#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	int maxx = 0;
	for (auto i : arr) maxx = max(maxx, i);
	cout << (maxx xor arr.back());
	return 0;
}