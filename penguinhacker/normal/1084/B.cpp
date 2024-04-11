#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll a[1000], s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll sum=accumulate(a, a+n, 0ll);
	if (s>sum) {
		cout << -1;
		return 0;
	}
	ll mn=*min_element(a, a+n);
	for (int i=0; i<n; ++i)
		s-=a[i]-mn;
	if (s<=0) {
		cout << mn;
		return 0;
	}
	cout << mn-(s+n-1)/n;
	return 0;
}