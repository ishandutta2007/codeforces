#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, l, r, a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> l >> r >> a >> b;
	int c = a - b;
	for (int i = 0; i < k; ++i)
		cout << (b / k) + (i < b % k ? 1 : 0) << " ";
   	for (int i = 0; i < n - k; ++i)
   	 	cout << (c / (n - k)) + (i < (c % (n - k)) ? 1 : 0) << " ";
	return 0;
}