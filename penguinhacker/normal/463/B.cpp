#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		ans=max(ans,a);
	}
	cout << ans;
	return 0;
}