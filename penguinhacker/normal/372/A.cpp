#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[500000], hidden=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);

	int ind=0;
	for (int i=(n+1)/2; i<n; ++i) {
		if (a[i]>=2*a[ind]) {
			hidden++;
			ind++;
		}
	}
	
	cout << n-hidden;
	return 0;
}