#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
ll n, a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll s=accumulate(a, a+n, 0ll);
	ll f=(2*s+n-n*n)/(2*n);
	ll s2=(2*f+n-1)*n/2;
	for (int i=0; i<n; ++i)
		cout << f+i+(i<s-s2) << " ";
	return 0;
}