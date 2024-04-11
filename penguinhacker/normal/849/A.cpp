#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	cout << (n%2&&a[0]%2&&a[n-1]%2?"Yes":"No");
	return 0;
}