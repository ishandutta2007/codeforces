#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int a, b;

void solve() {
	cin >> a >> b;
	cout << (b-(a%b))%b << '\n';
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