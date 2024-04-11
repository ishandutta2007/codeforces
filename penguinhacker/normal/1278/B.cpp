#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int a, b, n;

void solve() {
	cin >> a >> b;
	n = abs(a-b);

	int ans=0;
	while (ans*(ans+1)/2<n || (ans*(ans+1)/2-n)%2==1)
		ans++;
	cout << ans << '\n';
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