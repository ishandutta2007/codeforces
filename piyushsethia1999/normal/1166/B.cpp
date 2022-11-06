#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int k; cin >> k;
	int i;
	for (i = 5; i <= k; ++i) {
		if (k % i == 0) break; 
	} 
	int j = k / i;
	if (j < 5) {
		cout << -1; 
		exit(0);
	}
	char t[5] = {'a', 'e', 'i', 'o', 'u'};
	char a[i][j];
	for (int o = 0; o < i; ++o) {
		for (int k = 0; k < j; ++k) {
			a[o][k] = t[(o + k) % 5];
		} 
	}
	for (int o = 0; o < i; ++o) {
		for (int k = 0; k < j; ++k) cout << a[o][k];
	}
}