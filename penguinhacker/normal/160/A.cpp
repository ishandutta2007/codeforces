#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, sum=0, curr=0, a[100], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		sum+=a[i];
	}
	sort(a, a+n, greater<int> ());

	for (int i=0; i<n; ++i) {
		curr+=a[i];
		ans++;
		if (curr>sum/2) break;
	}
	cout << ans;
	return 0;
}