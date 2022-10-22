#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	if (n==1) {
		cout << "1 1\n0\n";
		cout << "1 1\n0\n";
		cout << "1 1\n" << -a[0];
		return 0;
	}
	cout << "1 1\n";
	ll x=n-a[0]%n;
	a[0]+=x;
	cout << x << "\n";

	cout << "2 " << n << "\n";
	for (int i=1; i<n; ++i) {
		x=a[i]%n;
		a[i]+=x*(n-1);
		cout << x*(n-1);
		cout << (i==n-1?"\n":" ");
	}
	cout << "1 " << n << "\n";
	for (int i=0; i<n; ++i) {
		assert(a[i]%n==0);
		cout << -a[i] << " ";
	}
	return 0;
}