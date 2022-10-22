#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll n, k;

void solve() {
	cin >> n >> k;
	if (n>=k*k && n%2==k%2)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}