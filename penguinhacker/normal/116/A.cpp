#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, cur=0, ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		cur += b-a;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}