#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;

void test_case() {
	cin >> n;
	int ans=0;
	for (int i=0; i<n; ++i) {
		int r;
		cin >> r;
		ans+=r==1||r==3;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}