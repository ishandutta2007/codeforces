#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n;
ll a[mxN], x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<(n+1)/2; ++i)
		cin >> a[i];
	cin >> x;
	if (x>0) {
		cout << (accumulate(a, a+(n+1)/2, 0ll)+x*(n/2)>0?n:-1);
		return 0;
	}
	for (int i=(n+1)/2-2; ~i; --i)
		a[i]+=a[i+1];
	for (int i=1; i<(n+1)/2; ++i)
		a[i]=min(a[i], a[i-1]-x);
	for (int i=0; i<(n+1)/2; ++i)
		if (a[i]+n/2*x>0) {
			cout << n-i;
			return 0;
		}
	cout << -1;
	return 0;
}