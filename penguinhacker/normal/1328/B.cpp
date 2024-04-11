#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, k;

void solve() {
	cin >> n >> k;
	
	int B1=n-2, B2;
	int cnt=0;

	while (cnt < k) {
		B2=n-1;
		if (B2-B1 >= k-cnt) {
			B2 = (n-k+cnt);
			cnt=k;
		}
		else {
			cnt += B2-B1;
			B1--;
		}
	}

	for (int i=0; i<n; ++i) {
		if (i==B1 || i==B2)
			cout << 'b';
		else
			cout << 'a';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}