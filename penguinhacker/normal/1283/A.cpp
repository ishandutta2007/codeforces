#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int h, m;

void solve() {
	cin >> h >> m;
	cout << (23-h)*60+(60-m) << '\n';
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