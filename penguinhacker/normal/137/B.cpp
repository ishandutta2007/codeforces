#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
bool occ[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, x; i<n; ++i) {
		cin >> x;
		occ[x]=1;
	}
	int cnt=n;
	for (int i=1; i<=n; ++i)
		if (occ[i])
			--cnt;
	cout << cnt;
	return 0;
}