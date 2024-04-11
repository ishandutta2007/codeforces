#include <bits/stdc++.h>
using namespace std;

#define ll long long

string grid[9];

void solve() {
	for (int i=0; i<9; ++i)
		cin >> grid[i];
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			int a=i*3+j, b=i+3*j;
			grid[a][b] = (grid[a][b]=='9'?'1':grid[a][b]+1);
		}
	for (int i=0; i<9; ++i)
		cout << grid[i] << '\n';
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