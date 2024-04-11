#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[101], b[101];
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=n; ++i) b[a[i]] = i;
	for (int i=1; i<=n; ++i)
		cout << b[i] << ' ';
	return 0;
}