#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, x=0, b[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> b[i];

	for (int i=0; i<n; ++i) {
		cout << x+b[i] << ' ';
		x = max(x, x+b[i]);
	}
	return 0;
}